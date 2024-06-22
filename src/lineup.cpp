
#include "../inc/lineup.h"

namespace Pt
{

Lineup::Lineup()
{
    reset_data();
}

Lineup::Lineup(const std::string &string)
{
    reset_data();
    Init(string);
}

Lineup::Lineup(const std::string &name, const std::string &string)
{
    reset_data();
    Init(string);
    this->lineup_name = name;
}

Lineup::~Lineup()
{
}

void Lineup::reset_data()
{
    this->ok = false;

    memset(this->plant, 0, GRID * sizeof(uint16_t));
    memset(this->plant_im, 0, GRID * sizeof(uint16_t));
    memset(this->plant_awake, 0, GRID * sizeof(uint16_t));
    memset(this->base, 0, GRID * sizeof(uint16_t));
    memset(this->base_im, 0, GRID * sizeof(uint16_t));
    memset(this->pumpkin, 0, GRID * sizeof(uint16_t));
    memset(this->pumpkin_im, 0, GRID * sizeof(uint16_t));
    memset(this->coffee, 0, GRID * sizeof(uint16_t));
    memset(this->coffee_im, 0, GRID * sizeof(uint16_t));
    memset(this->ladder, 0, GRID * sizeof(uint16_t));

    memset(this->items, 0, GRID * sizeof(uint16_t));

    this->rake_row = 0;
    this->scene = 2;

    this->weight = 0;

    this->lineup_name.clear();
    this->lineup_string.clear();
    this->lineup_code.clear();
}

void Lineup::Init(const std::string &string)
{
    std::regex regex_string("[0-5](,[a-fA-F0-9]{1,2} [1-6] [1-9] [0-2] [0-4]( [a-zA-Z0-9]{1,}){0,}){0,}");
    std::regex regex_code("([a-zA-Z0-9+/=]{18,164}|[a-zA-Z0-9-_=]{18,164})");

    if (std::regex_match(string, regex_string))
    {
        this->lineup_string = string;
        if (lineup_string_to_data())
        {
            this->ok = true;
        }
    }
    else if (std::regex_match(string, regex_code) //
             && string.size() % 4 == 0            //
             && std::count(string.begin(), string.end(), '=') <= 2)
    {
        this->lineup_code = string;
        if (lineup_code_to_data())
        {
            this->ok = true;
            decompress_data();
        }
    }

    this->weight += this->scene * 10000000000000000;
    for (int i = 0; i < GRID; i++)
    {
        if (plant[i] == 48)
            this->weight += 100000000000000; // 春哥
        if (plant[i] == 43)
            this->weight += 1000000000000; // 曾哥
        if (plant[i] == 42)
            this->weight += 10000000000; // 双子
        if (plant[i] == 45)
            this->weight += 100000000; // 冰瓜
        if (pumpkin[i] == 1)
            this->weight += 1000000; // 南瓜
        if (base[i] == 1)
            this->weight += 10000; // 睡莲
        if (base[i] == 2)
            this->weight += 100; // 花盆
        if (ladder[i] == 1)
            this->weight += 1; // 梯子
    }
}

bool Lineup::OK()
{
    return this->ok;
}

std::string Lineup::Generate()
{
    compress_data();
    data_to_lineup_code();

    return this->lineup_code;
}

std::vector<std::string> Lineup::split(const std::string &string, char seperator)
{
    std::vector<std::string> result;
    std::string::size_type prev = 0, pos = 0;
    while ((pos = string.find(seperator, pos)) != std::string::npos)
    {
        std::string sub_string(string.substr(prev, pos - prev));
        result.push_back(sub_string);
        prev = ++pos;
    }
    result.push_back(string.substr(prev, pos - prev));
    return result;
}

long Lineup::hex2dec(const std::string &string)
{
    char *ptr;
    long num;
    num = strtol(string.c_str(), &ptr, 16);
    return num;
}

bool Lineup::lineup_string_to_data()
{
    if (this->lineup_string.empty())
        return false;

    std::vector<std::string> str_list = split(this->lineup_string, ',');
    size_t count = str_list.size() - 1;

    std::string str_scene = str_list[0];
    if (str_scene == "0") // pool
        this->scene = 2;
    else if (str_scene == "1") // fog
        this->scene = 3;
    else if (str_scene == "2") // day
        this->scene = 0;
    else if (str_scene == "3") // night
        this->scene = 1;
    else if (str_scene == "4") // roof
        this->scene = 4;
    else if (str_scene == "5") // moon
        this->scene = 5;

    for (size_t i = 0; i < count; i++)
    {
        std::vector<std::string> item_str = split(str_list[i + 1], ' ');
        int item_type = hex2dec(item_str[0]);

        if (item_type < 0 || item_type > 0x32)
            continue;

        if (item_type == 16 || item_type == 33) // 睡莲 花盆
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            this->base[item_row * 9 + item_col] = (item_type == 16) ? 1 : 2;
            this->base_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 50) // 墓碑
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            this->base[item_row * 9 + item_col] = 3;
            this->base_im[item_row * 9 + item_col] = 0;
        }
        else if (item_type == 30) // 南瓜
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            this->pumpkin[item_row * 9 + item_col] = 1;
            this->pumpkin_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 35) // 咖啡
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            this->coffee[item_row * 9 + item_col] = 1;
            this->coffee_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 48) // 梯子 0x30
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            this->ladder[item_row * 9 + item_col] = 1;
        }
        else if (item_type == 49) // 钉耙 0x31
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            this->rake_row = item_row + 1;
        }
        else // 主要植物
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            int item_state_row = atoi(item_str[3].c_str());
            bool item_imitater = item_str[5] == "1";
            this->plant[item_row * 9 + item_col] = item_type + 1;
            this->plant_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
            this->plant_awake[item_row * 9 + item_col] = ((scene == 0 || scene == 2 || scene == 4) //
                                                          && this->may_sleep[item_type] && item_state_row == 0)
                                                             ? 0
                                                             : 1;
        }
    }

    return true;
}

bool Lineup::lineup_code_to_data()
{
    if (this->lineup_code.empty())
        return false;

    unsigned long size = 128;
    unsigned char buffer[128] = {0};

    size_t len = this->lineup_code.length();
    auto written = base64_decode(buffer, this->lineup_code.c_str(), len);
    // TODO 检测失败
    size = written;

    for (size_t i = 0; i < size; i++)
        buffer[i] = buffer[i] ^ (unsigned char)0x54;

    this->rake_row = buffer[size - 1] >> 4;
    this->scene = buffer[size - 1] & 0b00001111;
    if (this->scene >= 6)
        return false;
    if (this->rake_row != 0 && this->rake_row > ((this->scene == 2 || this->scene == 3) ? 6 : 5))
        return false;
    if ((this->scene == 2 || this->scene == 3) && (this->rake_row == 3 || this->rake_row == 4))
        return false;

    unsigned long cut_size = 6 * 9 * sizeof(uint16_t);
    int ret_decomp = uncompress((unsigned char *)this->items, &cut_size, buffer, size - 1);
    if (ret_decomp != Z_OK)
        return false;
    if (cut_size != ((scene == 2 || scene == 3) ? 6 : 5) * 9 * sizeof(uint16_t))
        return false;

    return true;
}

void Lineup::data_to_lineup_code()
{
    unsigned long size = 121; // compressBound(6*9*2)
    unsigned char buffer[128] = {0};
    unsigned long cut_size = ((this->scene == 2 || this->scene == 3) ? 6 : 5) * 9 * sizeof(uint16_t);
    compress2(buffer, &size, (unsigned char *)this->items, cut_size, Z_BEST_COMPRESSION);
    buffer[size - 1 + 1] = (this->rake_row << 4) | (this->scene & 0b00001111);

    for (size_t i = 0; i < size + 1; i++)
        buffer[i] = buffer[i] ^ (unsigned char)0x54;

    char str[256] = {0};
    size_t len = size + 1;
    auto written = base64_encode(str, buffer, len);

    std::string code(str);

    // CryptBinaryToStringA
    // code.erase(std::remove(code.begin(), code.end(), '\r'), code.end());
    // code.erase(std::remove(code.begin(), code.end(), '\n'), code.end());

    // std::cout << lineup << " " << lineup.size() << std::endl;
    lineup_code = code;
}

void Lineup::compress_data()
{
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            uint16_t item = 0;
            item += 0b1111110000000000 & (this->plant[r * 9 + c] << 10);
            item += 0b0000001000000000 & (this->plant_im[r * 9 + c] << 9);
            item += 0b0000000100000000 & (this->plant_awake[r * 9 + c] << 8);
            item += 0b0000000011000000 & (this->base[r * 9 + c] << 6);
            item += 0b0000000000100000 & (this->base_im[r * 9 + c] << 5);
            item += 0b0000000000010000 & (this->pumpkin[r * 9 + c] << 4);
            item += 0b0000000000001000 & (this->pumpkin_im[r * 9 + c] << 3);
            item += 0b0000000000000100 & (this->coffee[r * 9 + c] << 2);
            item += 0b0000000000000010 & (this->coffee_im[r * 9 + c] << 1);
            item += 0b0000000000000001 & (this->ladder[r * 9 + c] << 0);
            this->items[r * 9 + c] = item;
        }
    }
}

void Lineup::decompress_data()
{
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            uint16_t item = this->items[r * 9 + c];
            this->plant[r * 9 + c] = (item & 0b1111110000000000) >> 10;
            this->plant_im[r * 9 + c] = (item & 0b0000001000000000) >> 9;
            this->plant_awake[r * 9 + c] = (item & 0b0000000100000000) >> 8;
            this->base[r * 9 + c] = (item & 0b0000000011000000) >> 6;
            this->base_im[r * 9 + c] = (item & 0b0000000000100000) >> 5;
            this->pumpkin[r * 9 + c] = (item & 0b0000000000010000) >> 4;
            this->pumpkin_im[r * 9 + c] = (item & 0b0000000000001000) >> 3;
            this->coffee[r * 9 + c] = (item & 0b0000000000000100) >> 2;
            this->coffee_im[r * 9 + c] = (item & 0b0000000000000010) >> 1;
            this->ladder[r * 9 + c] = (item & 0b0000000000000001) >> 0;
        }
    }
}

} // namespace Pt
