
#include "window.h"

#define IDI_ICON 1001

namespace Pt
{

const char *plants[] =
    {
        "Peashooter",
        "Sunflower",
        "Cherry Bomb",
        "Wall-nut",
        "Potato Mine",
        "Snow Pea",
        "Chomper",
        "Repeater",
        "Puff-shroom",
        "Sun-shroom",
        "Fume-shroom",
        "Grave Buster",
        "Hypno-shroom",
        "Scaredy-shroom",
        "Ice-shroom",
        "Doom-shroom",
        "Lily Pad",
        "Squash",
        "Threepeater",
        "Tangle Kelp",
        "Jalapeno",
        "Spikeweed",
        "Torchwood",
        "Tall-nut",
        "Sea-shroom",
        "Plantern",
        "Cactus",
        "Blover",
        "Split Pea",
        "Starfruit",
        "Pumpkin",
        "Magnet-shroom",
        "Cabbage-pult",
        "Flower Pot",
        "Kernel-pult",
        "Coffee Bean",
        "Garlic",
        "Umbrella Leaf",
        "Marigold",
        "Melon-pult",
        "Gatling Pea",
        "Twin Sunflower",
        "Gloom-shroom",
        "Cattail",
        "Winter Melon",
        "Gold Magnet",
        "Spikerock",
        "Cob Cannon",
};

const char *zombies[] =
    {
        "Zombie",
        "Flag Zombie",
        "Conehead Zombie",
        "Pole Vaulting Zombie",
        "Buckethead Zombie",
        "Newspaper Zombie",
        "Screen Door Zombie",
        "Football Zombie",
        "Dancing Zombie",
        "Backup Dancer",
        "Ducky Tube Zombie",
        "Snorkel Zombie",
        "Zomboni",
        "Zombie Bobsled Team",
        "Dolphin Rider Zombie",
        "Jack-in-the-Box Zombie",
        "Balloon Zombie",
        "Digger Zombie",
        "Pogo Zombie",
        "Zombie Yeti",
        "Bungee Zombie",
        "Ladder Zombie",
        "Catapult Zombie",
        "Gargantuar",
        "Imp",
        "Dr. Zomboss",
        "Peashooter Zombie",
        "Wall-nut Zombie",
        "Jalapeno Zombie",
        "Gatling Pea Zombie",
        "Squash Zombie",
        "Tall-nut Zombie",
        "GigaGargantuar",
};

const char *modes[] =
    {
        "Adventure",
        "Survival: Day",
        "Survival: Night",
        "Survival: Pool",
        "Survival: Fog",
        "Survival: Roof",
        "Survival: Day (Hard)",
        "Survival: Night (Hard)",
        "Survival: Pool (Hard)",
        "Survival: Fog (Hard)",
        "Survival: Roof (Hard)",
        "Survival: Day (Endless)",
        "Survival: Night (Endless)",
        "Survival: Endless",
        "Survival: Fog (Endless)",
        "Survival: Roof (Endless)",
        "ZomBotany",
        "Wall-nut Bowling",
        "Slot Machine",
        "It's Raining Seeds",
        "Beghouled",
        "Invisi-ghoul",
        "Seeing Stars",
        "Zombiquarium",
        "Beghouled Twist",
        "Big Trouble Little Zombie",
        "Portal Combat",
        "Column Like You See'Em",
        "Bobseld Bonanza",
        "Zombie Nimble Zombie Quick",
        "Whack a Zombie",
        "Last Stand",
        "ZomBotany 2",
        "Wall-nut Bowling 2",
        "Pogo Party",
        "Dr. Zomboss's Revenge",
        "Art Challenge Wall-nut",
        "Sunny Day",
        "Unsodded",
        "Big Time",
        "Art Challenge Sunflower",
        "Air Raid",
        "Ice Level",
        "Zen Garden",
        "High Gravity",
        "Grave Danger",
        "Can You Dig It?",
        "Dark Stormy Night",
        "Bungee Blitz",
        "Squirrel",
        "Tree of Wisdom",
        "Vasebreaker",
        "To the Left",
        "Third Vase",
        "Chain Reaction",
        "M is for Metal",
        "Scary Potter",
        "Hokey Pokey",
        "Another Chain Reaction",
        "Ace of Vase",
        "Vasebreaker Endless",
        "I, Zombie",
        "I, Zombie Too",
        "Can You Dig It?",
        "Totally Nuts",
        "Dead Zeppelin",
        "Me Smash!",
        "ZomBoogie",
        "Three Hit Wonder",
        "All your brainz r belong to us",
        "I, Zombie Endless",
        "Upsell",
        "Intro",
};

const char *plants_zh[] =
    {
        "豌豆射手",
        "向日葵",
        "樱桃炸弹",
        "坚果",
        "土豆雷",
        "寒冰射手",
        "大嘴花",
        "双发射手",
        "小喷菇",
        "阳光菇",
        "大喷菇",
        "墓碑吞噬者",
        "魅惑菇",
        "胆小菇",
        "寒冰菇",
        "毁灭菇",
        "睡莲",
        "倭瓜",
        "三线射手",
        "缠绕海草",
        "火爆辣椒",
        "地刺",
        "火炬树桩",
        "高坚果",
        "海蘑菇",
        "路灯花",
        "仙人掌",
        "三叶草",
        "裂荚射手",
        "杨桃",
        "南瓜头",
        "磁力菇",
        "卷心菜投手",
        "花盆",
        "玉米投手",
        "咖啡豆",
        "大蒜",
        "叶子保护伞",
        "金盏花",
        "西瓜投手",
        "机枪射手",
        "双子向日葵",
        "忧郁蘑菇",
        "香蒲",
        "冰瓜",
        "吸金磁",
        "地刺王",
        "玉米加农炮",
};

const char *zombies_zh[] =
    {
        "普僵",
        "旗帜",
        "路障",
        "撑杆",
        "铁桶",
        "读报",
        "铁门",
        "橄榄",
        "舞王",
        "伴舞",
        "鸭子",
        "潜水",
        "冰车",
        "雪橇",
        "海豚",
        "小丑",
        "气球",
        "矿工",
        "跳跳",
        "雪人",
        "蹦极",
        "扶梯",
        "投篮",
        "白眼",
        "小鬼",
        "僵王",
        "豌豆",
        "坚果",
        "辣椒",
        "机枪",
        "倭瓜",
        "高墙",
        "红眼",
};

const char *modes_zh[] =
    {
        "冒险模式",
        "生存模式: 白天",
        "生存模式: 黑夜",
        "生存模式: 泳池",
        "生存模式: 雾夜",
        "生存模式: 屋顶",
        "生存模式: 白天 (困难)",
        "生存模式: 黑夜 (困难)",
        "生存模式: 泳池 (困难)",
        "生存模式: 雾夜 (困难)",
        "生存模式: 屋顶 (困难)",
        "生存模式: 白天 (无尽)",
        "生存模式: 黑夜 (无尽)",
        "生存模式: 无尽",
        "生存模式: 雾夜 (无尽)",
        "生存模式: 屋顶 (无尽)",
        "植物僵尸",
        "坚果保龄球",
        "老虎机",
        "雨中种植物",
        "宝石迷阵",
        "隐形食脑者",
        "看星星",
        "僵尸水族馆",
        "宝石迷阵转转看",
        "小僵尸大麻烦",
        "保护传送门",
        "你看, 他们像柱子一样",
        "雪橇区",
        "僵尸快跑",
        "锤僵尸",
        "谁笑到最后",
        "植物僵尸 2",
        "坚果保龄球 2",
        "跳跳舞会",
        "僵王博士的复仇",
        "坚果艺术",
        "晴天",
        "无草皮之地",
        "重要时间",
        "太阳花艺术",
        "空袭",
        "冰冻关卡",
        "禅境花园",
        "超乎寻常的压力",
        "坟墓模式",
        "你能把它挖出来吗?",
        "暴风雨之夜",
        "蹦极闪电战",
        "松鼠",
        "智慧树",
        "破罐者",
        "一路向左",
        "第三个罐子",
        "连锁反应",
        "M 的意思是金属",
        "胆怯的制陶工",
        "变戏法",
        "另一个连锁反应",
        "罐子王牌",
        "无尽的试炼",
        "我是僵尸",
        "我也是僵尸",
        "你能把它挖出来吗?",
        "完全傻了",
        "死亡飞艇",
        "我烂了!",
        "僵尸摇摆",
        "三连击",
        "你所有大脑都是属于我的",
        "我是僵尸无尽版",
        "促销",
        "介绍",
};

Fl_Choice_::Fl_Choice_(int x, int y, int w, int h, const char *l)
    : Fl_Choice(x, y, w, h, l)
{
}

Fl_Choice_::~Fl_Choice_()
{
}

int Fl_Choice_::handle(int event)
{
    switch (event)
    {
    case FL_ENTER:
        scrollable = true;
        return 1;
    case FL_LEAVE:
        scrollable = false;
        return 1;
    case FL_MOUSEWHEEL:
        if (scrollable)
        {
            if (Fl::event_dy() == -1) // 向上滚
            {
                int v = this->value() - 1;
                if (v < 0)
                    v = 0;
                this->value(v);
            }
            else // 向下滚
            {
                int v = this->value() + 1;
                if (v > this->size())
                    v = this->size();
                this->value(v);
            }
            redraw();
            do_callback();
        }
        return 1;
    default:
        return Fl_Choice::handle(event);
    }
}

Fl_Input_::Fl_Input_(int x, int y, int w, int h, const char *l)
    : Fl_Input(x, y, w, h, l)
{
}

Fl_Input_::~Fl_Input_()
{
}

int Fl_Input_::handle(int event)
{
    switch (event)
    {
    case FL_DND_RELEASE:
        this->value("");
        return 1;
    default:
        return Fl_Input::handle(event);
    }
}

SpawnTable::SpawnTable(int X, int Y, int W, int H, const char *L = 0)
    : Fl_Table(X, Y, W, H, L)
{
    // 宽: 75 + 35 * 20 + (35 + 25) + 2 = 837
    // 高: (18 + 3) + 18 * 33       + 2 = 617

    rows(ROWS);
    row_header(1);
    row_header_width(75);
    row_height_all(18);
    row_resize(0);

    cols(COLS);
    col_header(1);
    col_header_height(18 + 3);
    col_width_all(35);
    col_width(20 + 1 - 1, 35 + 25);
    col_resize(0);

    box(FL_NO_BOX); // 无边框

    end();
}

SpawnTable::~SpawnTable()
{
}

void SpawnTable::UpdateData(std::array<int, 1000> zombies_list)
{
    for (size_t r = 0; r < ROWS; r++)
        for (size_t c = 0; c < COLS; c++)
            data[r][c] = 0;
    total = 0;

    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 50; j++)
        {
            if (zombies_list[i * 50 + j] >= 33 || zombies_list[i * 50 + j] < 0)
                continue;
            data[zombies_list[i * 50 + j]][i] += 1;
            data[zombies_list[i * 50 + j]][20 + 1 - 1] += 1;
            total += 1;
        }
    }

    this->redraw();
}

void SpawnTable::draw_cell(TableContext context, int ROW = 0, int COL = 0, //
                           int X = 0, int Y = 0, int W = 0, int H = 0)
{
    static char s[100]; // 缓冲

    // 单波某种僵尸一般不超过 20 只，单轮某种僵尸一般不超过 300 只
    Fl_Color c_n = 0xffffff00u - 0x01000100u * (min(data[ROW][COL], 20) * 0xffu / 30);   // 背景颜色
    Fl_Color c_t = 0xffffff00u - 0x01010100u * (min(data[ROW][COL], 300) * 0xffu / 500); // 背景颜色(总数)
    Fl_Color c_f = 0xcccccc00u;                                                          // 旗帜波边框

    int Ys = 0; // 因为不画缺少的种类造成的纵向偏移
    for (int r = 0; r < ROW; r++)
        if (data[r][20 + 1 - 1] == 0)
            Ys += 18;

    switch (context)
    {
    case CONTEXT_STARTPAGE:
        extern Fl_Font ui_font;
        fl_font(ui_font, 13);
        return;

    case CONTEXT_COL_HEADER:
        if (total == 0) // 僵尸列表为空时不画波数表头
            break;

        if (COL == (20 + 1 - 1)) // 最后一列改为显示总数
            sprintf_s(s, "%s", std::string("(" + std::to_string(total) + ")").c_str());
        else
            sprintf_s(s, "w%i", COL + 1);

        fl_push_clip(X, Y, W, H);
        {
            fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, col_header_color());
            fl_color(FL_BLACK);
            fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
        }
        fl_pop_clip();

        return;

    case CONTEXT_ROW_HEADER:
        if (data[ROW][20 + 1 - 1] == 0) // 不画不出的僵尸种类
            break;

        sprintf_s(s, "%s", std::string("[" + std::to_string(ROW) + "]" + " " + zombies_zh[ROW] + "  ").c_str());

        fl_push_clip(X, Y - Ys, W, H);
        {
            fl_draw_box(FL_THIN_UP_BOX, X, Y - Ys, W, H, row_header_color());
            fl_color(FL_BLACK);
            fl_draw(s, X, Y - Ys, W, H, FL_ALIGN_RIGHT);
        }
        fl_pop_clip();

        return;

    case CONTEXT_CELL:
        if (data[ROW][20 + 1 - 1] == 0) // 不画不出的僵尸种类
            break;

        if (data[ROW][COL] == 0) // 某波某种僵尸数量为 0 干脆不显示
            sprintf_s(s, "");
        else
            sprintf_s(s, "%i", data[ROW][COL]);

        fl_push_clip(X, Y - Ys, W, H);
        {
            // 背景
            fl_color((COL == (20 + 1 - 1)) ? c_t : c_n);
            fl_rectf(X, Y - Ys, W, H);
            // 数据
            fl_color(FL_GRAY0);
            fl_draw(s, X, Y - Ys, W, H, FL_ALIGN_CENTER);
            // 边框
            fl_color((COL == (10 - 1) || COL == (20 - 1)) ? c_f : color());
            fl_rect(X, Y - Ys, W, H);
        }
        fl_pop_clip();

        return;

    default:
        return;
    }
}

SpawnWindow::SpawnWindow(int width, int height, const char *title)
    : Fl_Double_Window(width, height, title)
{
    // 参数 width height title 均被忽略

    // 设置窗口标题
    this->copy_label("出怪数量统计");

    // 设置窗口大小
    // 表格大小 837 x 617
    int w = 5 + 837 + 5;
    int h = 5 + 617 + 7;
    this->size(w, h);

    table_spawn = new SpawnTable(5, 5, 837, 617);
    button_update_details = new Fl_Button(5, 5, 75, 18 + 3, "···");
    button_zombies_list = new Fl_Menu_Button(5, 5, 837, 617, nullptr);
    box_mask_spawn_types = new Fl_Box(5, 5 + 18 + 3, 75, 18 * 33, nullptr);
    this->end();

    button_zombies_list->add("[刷新]");
    button_zombies_list->add("[保存]");
    button_zombies_list->add("[加载]");
    button_zombies_list->type(Fl_Menu_Button::POPUP3);
    button_zombies_list->value(0);

    extern Fl_Font ui_font;

    button_zombies_list->textfont(ui_font);

    emoji = IsWindows8OrGreater();

    button_zombies_list->replace(0, EMOJI("🔄", "[刷新]"));
    button_zombies_list->replace(1, EMOJI("💾", "[保存]"));
    button_zombies_list->replace(2, EMOJI("🔖", "[加载]"));
}

SpawnWindow::~SpawnWindow()
{
}

void SpawnWindow::UpdateData(std::array<int, 1000> zombies_list)
{
    table_spawn->UpdateData(zombies_list);

    int zombies_count[33] = {0};
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 50; j++)
        {
            if (zombies_list[i * 50 + j] >= 33 || zombies_list[i * 50 + j] < 0)
                continue;
            zombies_count[zombies_list[i * 50 + j]] += 1;
        }
    }
    int deleted_rows = 0;
    for (int r = 0; r < 33; r++)
        if (zombies_count[r] == 0)
            deleted_rows += 1;

    if (this->on)
    {
        std::string zs;
        for (int r = 0; r < 33; r++)
            if (zombies_count[r] != 0)
                zs += std::string("[" + std::to_string(r) + "]" + "  " + zombies[r] + "\n");
        box_mask_spawn_types->copy_tooltip(zs.c_str());
    }
    else
    {
        box_mask_spawn_types->copy_tooltip(nullptr);
    }

    int w = deleted_rows == 33 ? 450 : 5 + 837 + 5;
    int h = 5 + 617 + 7 - deleted_rows * 18;
    this->size(w, h);
    this->redraw();
}

void SpawnWindow::tooltips(bool on)
{
    button_update_details->copy_tooltip(on ? "Refresh" : "刷新");

    if (on) // this->on
    {
        std::string zs;
        for (int r = 0; r < 33; r++)
            if (table_spawn->data[r][20 + 1 - 1] != 0) // zombies_count[r]
                zs += std::string("[" + std::to_string(r) + "]" + "  " + zombies[r] + "\n");
        box_mask_spawn_types->copy_tooltip(zs.c_str());
    }
    else
    {
        box_mask_spawn_types->copy_tooltip(nullptr);
    }

    this->copy_label(on ? "Spawning Counting" : "出怪数量统计");

    this->on = on;
}

Window::Window(int width, int height, const char *title)
    : Fl_Double_Window(width, height, title)
{
    // 参数 width height title 均被忽略

    // 设置窗口标题
    this->copy_label("PvZ Toolkit - 植物大战僵尸全版本辅助工具");

    // 设置窗口大小
    int w = 95 * 4 + 10 * 2 + 10 * (4 + 1);          // 宽度 450
    int h = 25 * 6 + 10 * 2 + 10 * (6 + 1) + 30 + 5; // 高度 275
    this->size(w, h);

    // 坐标系统
    int m = 10;  // 控件边距
    int th = 30; // 选项卡高度
    int tb = 5;  // 选项卡底部边框
    int iw = 95; // 控件宽度 (1/4)
    int ih = 25; // 控件高度 (1/6)

    int x = m + m;           // 第一个控件的 x 坐标
    int y = m + th + tb + m; // 第一个控件的 y 坐标

    // (4 列的情况下) 根据列数返回 x 坐标
    auto c = [=](int col) -> int
    {
        return x + (iw + m) * (col - 1);
    };

    // (6 行的情况下) 根据行数返回 y 坐标
    auto r = [=](int row) -> int
    {
        return y + (ih + m) * (row - 1);
    };

    // 主窗体
    {
        tabs = new Fl_Tabs(m, m, w - m * 2, h - m * 2);
        {
            group_resource = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "资源");
            {
                check_unlock_sun_limit = new Fl_Round_Button(c(1) + 8, r(1), iw - 76, ih, "");
                input_sun = new Fl_Value_Input(c(1) + 45, r(1), iw - 15, ih, "");
                button_sun = new Fl_Button(c(2) + 40 - 10, r(1), iw - 45, ih, "阳光");
                box_money = new Fl_Box(c(1) + 8, r(2), iw - 76, ih, "钱包");
                input_money = new Fl_Value_Input(c(1) + 45, r(2), iw - 15, ih, "");
                button_money = new Fl_Button(c(2) + 40 - 10, r(2), iw - 45, ih, "金币");
                check_auto_collected = new Fl_Check_Button(c(3), r(3), iw - 15, ih, "自动收集");
                check_not_drop_loot = new Fl_Check_Button(c(4), r(3), iw, ih, "不掉战利品");
                check_fertilizer = new Fl_Check_Button(c(3), r(1), iw - 15, ih, "花肥无限");
                check_bug_spray = new Fl_Check_Button(c(4), r(1), iw, ih, "杀虫剂无限");
                check_tree_food = new Fl_Check_Button(c(3), r(2), iw - 15, ih, "树肥无限");
                check_chocolate = new Fl_Check_Button(c(4), r(2), iw, ih, "巧克力无限");
                box_wisdom_tree = new Fl_Box(c(1) + 8, r(3), iw - 76, ih, "树高");
                input_wisdom_tree = new Fl_Value_Input(c(1) + 45, r(3), iw - 15, ih, "");
                button_wisdom_tree = new Fl_Button(c(2) + 40 - 10, r(3), iw - 45, ih, "英尺");
                check_free_planting = new Fl_Check_Button(c(1), r(4), iw - 15, ih, "免费用卡");
                check_placed_anywhere = new Fl_Check_Button(c(2), r(4), iw - 15, ih, "随意放置");
                check_fast_belt = new Fl_Check_Button(c(3), r(4), iw - 15, ih, "无缝传送");
                check_lock_shovel = new Fl_Check_Button(c(4), r(4), iw - 15, ih, "连续铲子");
                choice_mode = new Fl_Choice_(c(1), r(5), iw + m + iw + 20, ih, "");
                choice_adventure = new Fl_Choice_(c(3) + 20, r(5), iw - 20 + 15, ih, "");
                button_mix = new Fl_Button(c(4) + 15, r(5), iw - 15, ih, "混乱关卡");
                input_level = new Fl_Value_Input(c(3) + 20, r(6), iw - 20 + 15, ih, "");
                button_level = new Fl_Button(c(4) + 15, r(6), iw - 15, ih, "无尽轮数");
                button_unlock = new Fl_Button(c(1), r(6), iw + 12, ih, "通关存档");
                button_direct_win = new Fl_Button(c(2) + 20 + 15, r(6), iw - 15, ih, "直接过关");
            }
            group_resource->end();

            group_battle = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "战场");
            {
                choice_row = new Fl_Choice_(c(1), r(1), iw - 10, ih, "");
                choice_col = new Fl_Choice_(c(1), r(2), iw - 10, ih, "");
                choice_plant = new Fl_Choice_(c(2) - 10, r(1), iw + 10 + 40, ih, "");
                choice_zombie = new Fl_Choice_(c(2) - 10, r(2), iw + 10 + 40, ih, "");
                button_put_plant = new Fl_Button(c(3) + 40, r(1), iw - 40 + 20, ih, "种植物");
                check_imitater = new Fl_Check_Button(c(4) + 20, r(1), iw - 20, ih, "模仿者");
                button_put_zombie = new Fl_Button(c(3) + 40, r(2), iw - 40 + 20, ih, "出僵尸");
                button_put_ladder = new Fl_Button(c(3) + 40, r(3), iw - 40 + 20, ih, "搭梯子");
                button_put_grave = new Fl_Button(c(4) + 20, r(2), iw - 20, ih, "冒墓碑");
                button_put_rake = new Fl_Button(c(4) + 20, r(3), iw - 20, ih, "放钉耙");
                button_lawn_mower = new Fl_Menu_Button(c(1), r(3), iw - 10, ih, "小推车");
                choice_item = new Fl_Choice_(c(2) - 10, r(3), iw + 10 - 20, ih, "");
                button_clear = new Fl_Button(c(2) + iw - 20 + m, r(3), iw - 45, ih, "清除");
                check_plant_invincible = new Fl_Check_Button(c(1), r(4), iw - 15, ih, "植物无敌");
                check_plant_weak = new Fl_Check_Button(c(2), r(4), iw - 15, ih, "植物脆弱");
                check_zombie_invincible = new Fl_Check_Button(c(3), r(4), iw - 15, ih, "僵尸无敌");
                check_zombie_weak = new Fl_Check_Button(c(4), r(4), iw - 15, ih, "僵尸虚弱");
                check_reload_instantly = new Fl_Check_Button(c(1), r(5), iw - 15, ih, "立刻装填");
                check_mushroom_awake = new Fl_Check_Button(c(2), r(5), iw - 15, ih, "蘑菇睡醒");
                check_stop_spawning = new Fl_Check_Button(c(3), r(5), iw - 15, ih, "暂停刷怪");
                check_stop_zombies = new Fl_Check_Button(c(4), r(5), iw - 15, ih, "停滞不前");
                check_lock_butter = new Fl_Check_Button(c(1), r(6), iw - 15, ih, "只投黄油");
                check_no_crater = new Fl_Check_Button(c(2), r(6), iw - 15, ih, "核弹无坑");
                check_no_ice_trail = new Fl_Check_Button(c(3), r(6), iw - 15, ih, "冰车无痕");
                check_zombie_not_explode = new Fl_Check_Button(c(4), r(6), iw - 15, ih, "丑椒不爆");
            }
            group_battle->end();

            group_lineup = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "阵型");
            {
                choice_slot = new Fl_Choice_(c(1), r(1), iw - 10, ih, "");
                choice_seed = new Fl_Choice_(c(2) - 10, r(1), iw + 10 + 40, ih, "");
                button_seed = new Fl_Button(c(3) + 40, r(1), iw - 40 + 20, ih, "换卡片");
                check_seed_imitater = new Fl_Check_Button(c(4) + 20, r(1), iw - 20, ih, "模仿者");
                check_lineup_mode = new Fl_Check_Button(c(1), r(2), iw + 12, ih, "快捷布阵模式");
                button_auto_ladder = new Fl_Button(c(2) + 12, r(2), iw - 12, ih, "智能搭梯");
                button_put_lily_pad = new Fl_Menu_Button(c(3), r(2), iw, ih, "水路睡莲");
                button_put_flower_pot = new Fl_Menu_Button(c(4), r(2), iw, ih, "屋顶花盆");
                button_reset = new Fl_Button(c(1), r(3), iw + 12, ih, "重置场地");
                choice_scene = new Fl_Choice_(c(2) + 12, r(3), iw - 12, ih, "");
                button_load_lineup = new Fl_Button(c(3), r(3), iw * 2 + 10, ih, "加载阵型列表文件 (***.yml)");
                choice_lineup_name[0] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[1] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[2] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[3] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[4] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[5] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                buffer_lineup_string = new Fl_Text_Buffer();
                editor_lineup_string = new Fl_Text_Editor(c(1), r(4), iw * 4 + 10 * 3, ih * 2 + 10 + 2, "");
                button_get_lineup = new Fl_Button(c(1), r(6), iw - 15, ih, "获取代码");
                button_copy_lineup = new Fl_Button(c(2) - 15, r(6), iw - 15, ih, "复制导出");
                button_paste_lineup = new Fl_Button(c(3) + 15 + 15, r(6), iw - 15, ih, "粘贴导入");
                button_set_lineup = new Fl_Button(c(4) + 15, r(6), iw - 15, ih, "布置阵型");
                button_capture = new Fl_Button(c(3) - 15 - 15, r(6), 15 * 4 - m, ih, "截图");
            }
            group_lineup->end();

            group_spawn = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "出怪");
            {
                int tmp[20] = {2, 3, 4, 5, 6,       //
                               7, 8, 11, 12, 14,    //
                               15, 16, 17, 18, 19,  //
                               20, 21, 22, 23, 32}; //
                memcpy(spawn_type, tmp, sizeof(tmp));
                for (size_t row = 0; row < 4; row++)
                    for (size_t col = 0; col < 5; col++)
                        check_zombie[row * 5 + col] = new Fl_Check_Button                               //
                            (x + 8 + (iw - 22 + m) * col, y + 5 + (ih + 7 + m) * row, iw - 42, ih, ""); //
                button_show_details = new Fl_Button(c(1), r(6), iw, ih, "查看详情");
                choice_giga_weight = new Fl_Choice_(c(2) + 5, r(6), iw - 20, ih, "");
                check_giga_limit = new Fl_Check_Button(c(3) - 55 + 40, r(6), iw - 40, ih, "变速");
                button_set_spawn = new Fl_Button(c(4) - 55, r(6), iw + 55 - 5, ih, "极限出怪 (均匀填充)");
                button_spawn_extra = new Fl_Menu_Button(m, m + th, w - m * 2, h - m * 2 - th - 42, nullptr);
                button_spawn_mode = new Fl_Menu_Button(c(4) - 55, r(6), iw + 55 - 5, ih, "选择刷怪模式：");
            }
            group_spawn->end();

            group_others = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "杂项");
            {
                choice_music = new Fl_Choice_(c(1), r(1), iw + m + iw - 15, ih, "");
                button_music = new Fl_Button(c(3) - 15, r(1), iw, ih, "背景音乐");
                button_userdata = new Fl_Button(c(4) - 15, r(1), iw + 15, ih, "存档文件夹");
                check_no_fog = new Fl_Check_Button(c(1), r(2), iw - 15, ih, "清除浓雾");
                check_see_vase = new Fl_Check_Button(c(2) - 15, r(2), iw - 15, ih, "罐子透视");
                check_background = new Fl_Check_Button(c(3) - 30, r(2), iw + 15, ih, "允许后台运行");
                check_readonly = new Fl_Check_Button(c(4) - 15, r(2), iw + 15, ih, "禁止存档删档");
                button_file = new Fl_Button(c(1), r(3), iw - 20, ih, "选择文件");
                input_file = new Fl_Input_(c(2) - 20, r(3), iw + 20 + m + iw + 45, ih, "");
                button_unpack = new Fl_Button(c(4) + 45, r(3), iw - 45, ih, "解包");
                button_dir = new Fl_Button(c(1), r(4), iw - 20, ih, "选择目录");
                input_dir = new Fl_Input_(c(2) - 20, r(4), iw + 20 + m + iw + 45, ih, "");
                button_pack = new Fl_Button(c(4) + 45, r(4), iw - 45, ih, "打包");
                choice_debug = new Fl_Choice_(c(1), r(5), iw - 30, ih, "");
                button_debug = new Fl_Button(c(2) - 30, r(5), iw - 40, ih, "调试");
                choice_speed = new Fl_Choice_(c(3) - 70 + 10, r(5), iw - 30, ih, "");
                button_speed = new Fl_Button(c(4) - 100 + 10, r(5), iw - 40, ih, "速度");
                check_limbo_page = new Fl_Check_Button(c(4) - 15, r(5), iw + 15, ih, "显示隐藏页面");
                choice_scheme = new Fl_Choice_(c(1), r(6), iw - 15, ih, "");
                check_tooltips = new Fl_Check_Button(c(2) - 15, r(6), iw + 35, ih, "English Tooltips");
                button_document = new Fl_Button(c(3) + 30, r(6), iw - 15, ih, "文档");
                button_about = new Fl_Button(c(4) + 15, r(6), iw - 15, ih, "关于 ...");
            }
            group_others->end();
        }
        tabs->end();

        box_mask_resource = new Fl_Box(10 + 1 + (40 + 2) * 0, 10, 40, 30, "");
        box_mask_battle = new Fl_Box(10 + 1 + (40 + 2) * 1, 10, 40, 30, "");
        box_mask_lineup = new Fl_Box(10 + 1 + (40 + 2) * 2, 10, 40, 30, "");
        box_mask_spawn = new Fl_Box(10 + 1 + (40 + 2) * 3, 10, 40, 30, "");
        box_mask_others = new Fl_Box(10 + 1 + (40 + 2) * 4, 10, 40, 30, "");

        game_status = new Fl_Box(230, 12, 190, 25, "");
        game_status_tip = new Fl_Box(425, 12, 15, 25, "");
    }
    this->end();

    // 默认值

    // 选项卡颜色
    group_resource->selection_color(FL_DARK2);
    group_battle->selection_color(FL_DARK2);
    group_lineup->selection_color(FL_DARK2);
    group_spawn->selection_color(FL_DARK2);
    group_others->selection_color(FL_DARK2);
    tabs->selection_color(FL_WHITE);

    // 阳光
    input_sun->bounds(0, 9990);
    input_sun->value(8000);

    // 金钱
    input_money->bounds(0, 99999);
    input_money->value(99999);

    // 智慧树
    input_wisdom_tree->bounds(0, 1000);
    input_wisdom_tree->value(1437);

    for (size_t i = 0; i < 73; i++)
        choice_mode->add(("[" + std::to_string(i) + "]" + " " + modes_zh[i]).c_str());

    // 默认无尽模式
    choice_mode->value(13);

    for (size_t j = 1; j <= 5; j++)
        for (size_t k = 1; k <= 10; k++)
            choice_adventure->add((std::to_string(j) + " - " + std::to_string(k)).c_str());

    choice_adventure->value(39); // 4-10
    choice_adventure->deactivate();

    // 1010 * 2 + 2 = 2022
    input_level->bounds(0, 10000000);
    input_level->value(1010);

    choice_row->add("所有行");
    choice_row->add("第 1 行");
    choice_row->add("第 2 行");
    choice_row->add("第 3 行");
    choice_row->add("第 4 行");
    choice_row->add("第 5 行");
    choice_row->add("第 6 行");

    choice_row->value(1); // 第 1 行

    choice_col->add("所有列");
    choice_col->add("第 1 列");
    choice_col->add("第 2 列");
    choice_col->add("第 3 列");
    choice_col->add("第 4 列");
    choice_col->add("第 5 列");
    choice_col->add("第 6 列");
    choice_col->add("第 7 列");
    choice_col->add("第 8 列");
    choice_col->add("第 9 列");

    choice_col->value(1); // 第 1 列

    for (size_t i = 0; i < 48; i++)
    {
        std::string p = "[" + std::to_string(i) + "]" + " " + plants_zh[i];
        choice_plant->add(p.c_str());
    }
    choice_plant->value(0);

    for (size_t i = 0; i < 33; i++)
    {
        std::string z = "[" + std::to_string(i) + "]" + " " + zombies_zh[i];
        choice_zombie->add(z.c_str());
    }
    choice_zombie->value(0);

    button_lawn_mower->add("[启动]");
    button_lawn_mower->add("[删除]");
    button_lawn_mower->add("[恢复]");

    choice_item->add("植物");
    choice_item->add("僵尸");
    choice_item->add("梯子");
    choice_item->add("墓碑");
    choice_item->add("钉耙");

    choice_item->value(3); // 墓碑

    choice_slot->add("第 1 格");
    choice_slot->add("第 2 格");
    choice_slot->add("第 3 格");
    choice_slot->add("第 4 格");
    choice_slot->add("第 5 格");
    choice_slot->add("第 6 格");
    choice_slot->add("第 7 格");
    choice_slot->add("第 8 格");
    choice_slot->add("第 9 格");
    choice_slot->add("第 10 格");

    choice_slot->value(0); // 第一格卡槽

    for (size_t i = 0; i < 48; i++)
    {
        std::string p = "[" + std::to_string(i) + "]" + " " + plants_zh[i];
        choice_seed->add(p.c_str());
    }

    choice_seed->value(0); // 第一张卡片

    for (size_t i = 0; i < 8; i++)
    {
        std::string label;
        for (unsigned int c = 1; c <= 9; c++)
            label += (lily_pad_col_lower[i] <= c && c <= lily_pad_col_upper[i])
                         ? "■"
                         : "□";
        button_put_lily_pad->add(label.c_str());
    }

    for (size_t i = 0; i < 7; i++)
    {
        std::string label;
        for (unsigned int c = 1; c <= 9; c++)
            label += (flower_pot_col_lower[i] <= c && c <= flower_pot_col_upper[i])
                         ? "■"
                         : "□";
        button_put_flower_pot->add(label.c_str());
    }

    choice_scene->add("[0] 白天");
    choice_scene->add("[1] 黑夜");
    choice_scene->add("[2] 泳池");
    choice_scene->add("[3] 雾夜");
    choice_scene->add("[4] 屋顶");
    choice_scene->add("[5] 月夜");

    choice_scene->value(2); // 泳池

    lineups.clear();
    lineup_count[0] = 0;
    lineup_count[1] = 0;
    lineup_count[2] = 0;
    lineup_count[3] = 0;
    lineup_count[4] = 0;
    lineup_count[5] = 0;

    choice_lineup_name[0]->hide();
    choice_lineup_name[1]->hide();
    choice_lineup_name[2]->hide();
    choice_lineup_name[3]->hide();
    choice_lineup_name[4]->hide();
    choice_lineup_name[5]->hide();

    editor_lineup_string->buffer(buffer_lineup_string);
    editor_lineup_string->wrap_mode(Fl_Text_Editor::WRAP_AT_BOUNDS, 0);
    editor_lineup_string->deactivate(); // 不可编辑

    // 出怪名称
    for (size_t i = 0; i < 20; i++)
        check_zombie[i]->copy_label(zombies_zh[spawn_type[i]]);

    // 非旗帜波红眼权重范围
    for (size_t w = 1000; w <= 6000; w += 100)
        choice_giga_weight->add(std::to_string(w).c_str());
    choice_giga_weight->value(0);

    // 默认极限出怪的情况
    choice_giga_weight->deactivate();
    check_giga_limit->activate();

    button_spawn_extra->add("[清空已选]", 0, cb_clear_checked_zombies, this);
    button_spawn_extra->add("[取消限制]", 0, cb_disable_limit_species, this);
    button_spawn_extra->type(Fl_Menu_Button::POPUP3);
    button_spawn_extra->value(0);

    button_spawn_mode->add("自然出怪 (游戏生成)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->add("极限出怪 (均匀填充)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->add("模拟出怪 (加权随机)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->type(Fl_Menu_Button::POPUP3);
    button_spawn_mode->value(1); // 默认极限刷怪

    choice_music->add("[1] Grasswalk");
    choice_music->add("[2] Moongrains");
    choice_music->add("[3] Watery Graves");
    choice_music->add("[4] Rigor Mormist");
    choice_music->add("[5] Graze the Roof");
    choice_music->add("[6] Choose Your Seeds");
    choice_music->add("[7] Crazy Dave");
    choice_music->add("[8] Zen Garden");
    choice_music->add("[9] Cerebrawl");
    choice_music->add("[10] Loonboon");
    choice_music->add("[11] Ultimate Battle");
    choice_music->add("[12] Brainiac Maniac");

    choice_music->value(4); // Graze the Roof

    choice_debug->add("关闭");
    choice_debug->add("出怪");
    choice_debug->add("音乐");
    choice_debug->add("内存");
    choice_debug->add("碰撞");

    choice_debug->value(0); // 关闭

    choice_speed->add("10x");
    choice_speed->add("5x");
    choice_speed->add("2x");
    choice_speed->add("1x");
    choice_speed->add("0.5x");
    choice_speed->add("0.2x");
    choice_speed->add("0.1x");

    choice_speed->value(3); // 1x

    choice_scheme->add("base");
    choice_scheme->add("plastic");
    choice_scheme->add("gtk+");
    choice_scheme->add("gleam");

    choice_scheme->value(0); // base

    // 默认打开后台运行和显示隐藏游戏
    check_background->value(1);
    check_limbo_page->value(1);

    // 默认显示出怪选项卡
    tabs->value(group_spawn);

    // 回调函数

    choice_mode->callback(cb_mode, this); // cb_tooltips
    choice_adventure->callback(cb_tooltips, this);

    choice_row->callback(cb_tooltips, this);
    choice_col->callback(cb_tooltips, this);
    choice_plant->callback(cb_tooltips, this);
    choice_zombie->callback(cb_tooltips, this);

    choice_item->callback(cb_tooltips, this);
    choice_slot->callback(cb_tooltips, this);
    choice_seed->callback(cb_tooltips, this);

    button_load_lineup->callback(cb_load_lineup, this);
    choice_scene->callback(cb_switch_lineup_scene, this); // cb_tooltips
    choice_lineup_name[0]->callback(cb_show_lineup_string, this);
    choice_lineup_name[1]->callback(cb_show_lineup_string, this);
    choice_lineup_name[2]->callback(cb_show_lineup_string, this);
    choice_lineup_name[3]->callback(cb_show_lineup_string, this);
    choice_lineup_name[4]->callback(cb_show_lineup_string, this);
    choice_lineup_name[5]->callback(cb_show_lineup_string, this);
    button_copy_lineup->callback(cb_copy_lineup, this);
    button_paste_lineup->callback(cb_paste_lineup, this);

    check_zombie[0]->callback(cb_spawn_mutex_0, this);
    check_zombie[3]->callback(cb_spawn_mutex_3, this);
    for (size_t i = 0; i < 20; i++)
    {
        int t = spawn_type[i];
        if ((i != 0) && (i != 3) && (t != 19) && (t != 20))
            check_zombie[i]->callback(cb_spawn_count_check, this);
    }

    choice_music->callback(cb_tooltips, this);

    button_file->callback(cb_open_file, this);
    button_dir->callback(cb_open_dir, this);

    choice_debug->callback(cb_tooltips, this);
    choice_speed->callback(cb_tooltips, this);

    choice_scheme->callback(cb_scheme, this); // cb_tooltips
    // check_tooltips->callback(cb_tooltips, this); // 重载
    button_document->callback(cb_document, this);
    button_about->callback(cb_about, this);

    // 设置字体

    extern Fl_Font ui_font;
    extern Fl_Font ls_font;

    for (int i = 0; i < this->children(); i++)
        this->child(i)->labelfont(ui_font);
    {
        for (int i = 0; i < tabs->children(); i++)
        {
            tabs->child(i)->labelfont(ui_font);
            tabs->child(i)->labelsize(tabs->child(i)->labelsize() + 1);
        }
        {
            for (int i = 0; i < group_resource->children(); i++)
                group_resource->child(i)->labelfont(ui_font);
            input_sun->textfont(ui_font);
            input_money->textfont(ui_font);
            input_wisdom_tree->textfont(ui_font);
            choice_mode->textfont(ui_font);
            choice_adventure->textfont(ui_font);
            input_level->textfont(ui_font);
        }
        {
            for (int i = 0; i < group_battle->children(); i++)
                group_battle->child(i)->labelfont(ui_font);
            choice_row->textfont(ui_font);
            choice_col->textfont(ui_font);
            choice_plant->textfont(ui_font);
            choice_zombie->textfont(ui_font);
            button_lawn_mower->textfont(ui_font);
            choice_item->textfont(ui_font);
        }
        {
            for (int i = 0; i < group_lineup->children(); i++)
                group_lineup->child(i)->labelfont(ui_font);
            choice_slot->textfont(ui_font);
            choice_seed->textfont(ui_font);
            // button_put_lily_pad
            // button_put_flower_pot
            choice_scene->textfont(ui_font);
            choice_lineup_name[0]->textfont(ui_font);
            choice_lineup_name[1]->textfont(ui_font);
            choice_lineup_name[2]->textfont(ui_font);
            choice_lineup_name[3]->textfont(ui_font);
            choice_lineup_name[4]->textfont(ui_font);
            choice_lineup_name[5]->textfont(ui_font);
            editor_lineup_string->textfont(ls_font); // 阵型字符串特殊字体
            editor_lineup_string->textsize(16);
        }
        {
            for (int i = 0; i < group_spawn->children(); i++)
                group_spawn->child(i)->labelfont(ui_font);
            // choice_giga_weight->textfont(ui_font);
            button_spawn_extra->textfont(ui_font);
            button_spawn_mode->textfont(ui_font);
        }
        {
            for (int i = 0; i < group_others->children(); i++)
                group_others->child(i)->labelfont(ui_font);
            choice_music->textfont(ui_font);
            input_file->textfont(ui_font);
            input_dir->textfont(ui_font);
            choice_debug->textfont(ui_font);
            choice_speed->textfont(ui_font);
            choice_scheme->textfont(ui_font);
        }
    }

    // Emoji

    emoji = IsWindows8OrGreater();
    emoji_i = IsWindows8Point1OrGreater();

    if (emoji)
    {
        box_money->copy_label("💰");
        box_wisdom_tree->copy_label("🌳");
        button_capture->copy_label("📷");
    }

    button_unlock->copy_label(EMOJI("🏆", "通关存档"));

    button_lawn_mower->replace(0, EMOJI("➡️", "[启动]"));
    button_lawn_mower->replace(1, EMOJI("🆑", "[删除]"));
    button_lawn_mower->replace(2, EMOJI("🔄", "[恢复]"));

    button_reset->copy_label(EMOJI("⏳", "重置场地"));

    button_spawn_extra->replace(0, EMOJI("❌", "[清空已选]"));
    button_spawn_extra->replace(1, EMOJI("❎", "[取消限制]"));

    button_show_details->copy_label(EMOJI("📈", "查看详情"));

    button_music->copy_label(EMOJI("🎵", "背景音乐"));
    button_userdata->copy_label(EMOJI("💾", "存档文件夹"));
    button_document->copy_label(EMOJI("🌏", "文档"));

    // 默认运行的回调函数

    // 自动导入阵型列表
    import_lineup_list(true);

    // 获取阵型的字符串
    choice_scene->do_callback();

    // 设置控件工具提示
    check_tooltips->do_callback();

    // this->show(); // 在 main() 里带参调用

    ReadSettings(); // 读取设置

    // 窗口居中显示
    this->position((Fl::w() - this->w()) / 2, (Fl::h() - this->h()) / 2);

    // 默认焦点控件
    button_sun->take_focus();
}

Window::~Window()
{
    WriteSettings(); // 保存设置
}

void Window::ReadSettings()
{
    // 注册表配置版本 v1

    bool first_open = true;

    HKEY hKey;
    DWORD r = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                            0, KEY_QUERY_VALUE, &hKey);
    if (r == ERROR_SUCCESS)
    {
        first_open = false;

        LSTATUS status;
        DWORD dwType;
        DWORD dwSize;

        wchar_t lang[15];    // 语言
        DWORD scale;         // 缩放
        int scheme;          // 样式
        wchar_t zombies[20]; // 出怪
        int mode;            // 模式
        int sun;             // 阳光
        int money;           // 金币
        int level;           // 轮数
        unsigned int page;   // 页面

        dwType = REG_SZ;
        dwSize = sizeof(lang);
        status = RegQueryValueExW(hKey, L"Language", 0, &dwType, (LPBYTE)&lang, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            if (std::wstring(lang) == L"English")
            {
                check_tooltips->value(1);
                check_tooltips->do_callback();
            }
        }

        dwType = REG_DWORD;
        dwSize = sizeof(scale);
        status = RegQueryValueExW(hKey, L"ScaleFactor", 0, &dwType, (LPBYTE)&scale, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            float factor = *(float *)(&scale);
            // std::cout << "ScaleFactor: " << factor << std::endl;
            if (factor != 1.0f) // TODO: Do what?
                Fl::screen_scale(this->screen_num(), factor);
        }

        dwType = REG_DWORD;
        dwSize = sizeof(scheme);
        status = RegQueryValueExW(hKey, L"Scheme", 0, &dwType, (LPBYTE)&scheme, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            if (0 <= scheme && scheme < 4)
            {
                choice_scheme->value(scheme);
                choice_scheme->do_callback();
            }
        }

        dwType = REG_SZ;
        dwSize = sizeof(zombies);
        status = RegQueryValueExW(hKey, L"SpawnTypes", 0, &dwType, (LPBYTE)&zombies, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            for (size_t i = 0; i < 20; i++)
                this->check_zombie[i]->value(zombies[i] == L'1' ? 1 : 0);
            cb_spawn_count_check();
        }

        dwType = REG_DWORD;
        dwSize = sizeof(mode);
        status = RegQueryValueExW(hKey, L"SpawnMode", 0, &dwType, (LPBYTE)&mode, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            if (0 <= mode && mode < 3)
            {
                button_spawn_mode->value(mode);
                cb_switch_spawn_mode();
            }
        }

        dwType = REG_DWORD;
        dwSize = sizeof(sun);
        status = RegQueryValueExW(hKey, L"ValueSun", 0, &dwType, (LPBYTE)&sun, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            if (0 <= sun && sun <= 9990)
                input_sun->value(sun);
        }

        dwType = REG_DWORD;
        dwSize = sizeof(money);
        status = RegQueryValueExW(hKey, L"ValueMoney", 0, &dwType, (LPBYTE)&money, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            if (0 <= money && money <= 99999)
                input_money->value(money);
        }

        dwType = REG_DWORD;
        dwSize = sizeof(level);
        status = RegQueryValueExW(hKey, L"ValueLevel", 0, &dwType, (LPBYTE)&level, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            if (0 <= level && level <= 10000000)
                input_level->value(level);
        }

        dwType = REG_DWORD;
        dwSize = sizeof(page);
        status = RegQueryValueExW(hKey, L"CurrentPage", 0, &dwType, (LPBYTE)&page, &dwSize);
        if (status == ERROR_SUCCESS)
        {
            std::vector<Fl_Widget *> vp = {
                group_resource,
                group_battle,
                group_lineup,
                group_spawn,
                group_others,
            };
            if (0 <= page && page < vp.size())
            {
                tabs->value(vp[page]);
            }
        }

        RegCloseKey(hKey);
    }

    if (first_open)
    {
        // 0804  2052  zh-CN  Chinese (Simplified) - China
        // 0404  1028  zh-TW  Chinese (Traditional) - Taiwan
        // 0C04  3076  zh-HK  Chinese - Hong Kong SAR
        // 1404  5124  zh-MO  Chinese - Macao SAR
        // 1004  4100  zh-SG  Chinese - Singapore
        LANGID li = GetUserDefaultLangID();
        // std::cout << "LangID: " << li << std::endl;
        // 非中文区域显示英语提示框
        bool non_chinese = li != 2052 && //
                           li != 1028 && //
                           li != 3076 && //
                           li != 5124 && //
                           li != 4100;
        if (non_chinese)
        {
            check_tooltips->value(1);
            check_tooltips->do_callback();
        }

        int dpi = 96;
        HDC dc = GetDC(nullptr);
        if (dc != nullptr)
        {
            // int virtual_width = GetDeviceCaps(dc, HORZRES);
            // int physical_width = GetDeviceCaps(dc, DESKTOPHORZRES);
            // dpi = 96 * physical_width / virtual_width;
            int dpi_x = GetDeviceCaps(dc, LOGPIXELSX);
            int dpi_y = GetDeviceCaps(dc, LOGPIXELSY);
            dpi = (dpi_x + dpi_y) / 2;
            ReleaseDC(nullptr, dc);
        }
        if (dpi > 96)
        {
            Fl::screen_scale(this->screen_num(), dpi / 96.0f);
            std::string text = std::string()                                 //
                               + "软件界面已跟随系统缩放比例："              //
                               + std::to_string(dpi * 100 / 96) + "%%。\n\n" //
                               + "单独按 Esc 键可恢复默认的窗口大小，\n"     //
                               + "同时按 Ctrl 和 + / - 键可放大缩小窗口。";  //
            fl_message_title("界面缩放");
            fl_message(text.c_str());
        }

#pragma warning(disable : 4996)
        DWORD dwVersion = 0;
        DWORD dwBuild = 0;
        dwVersion = GetVersion();
        if (dwVersion < 0x80000000)
            dwBuild = (DWORD)(HIWORD(dwVersion));
#pragma warning(default : 4996)

        if (dwBuild >= 6000)         // Vista
            choice_scheme->value(3); //       gleam
        if (dwBuild >= 7600)         // 7
            choice_scheme->value(3); //       gleam
        if (dwBuild >= 9200)         // 8
            choice_scheme->value(0); //       base
        if (dwBuild >= 9600)         // 8.1
            choice_scheme->value(0); //       base
        if (dwBuild >= 10240)        // 10
            choice_scheme->value(0); //       base
        if (dwBuild >= 22000)        // 11
            choice_scheme->value(2); //       gtk+
        choice_scheme->do_callback();

        // 第一次打开时显示文档
        fl_message_title("在线文档");
        int c = fl_choice("这是你首次运行 PvZ Toolkit，要先阅读一下在线教程文档吗？\n" //
                          "也可以在修改器界面的“杂项”页面点击“文档”按钮来访问。",      //
                          "No", "Yes", 0);
        if (c == 1)
            cb_document();
    }
}

void Window::WriteSettings()
{
    // 注册表配置版本 v1

    // 语言
    wchar_t langChinese[] = L"简体中文";
    wchar_t langEnglish[] = L"English";

    // 缩放
    float scale = Fl::screen_scale(this->screen_num());

    // 样式
    int scheme = choice_scheme->value();

    // 出怪
    wchar_t zombies[20] = {0};
    for (size_t i = 0; i < 20; i++)
        zombies[i] = (this->check_zombie[i]->value() == 1 ? L'1' : L'0');

    // 模式
    int mode = button_spawn_mode->value();

    // 阳光
    int sun = static_cast<int>(input_sun->value());

    // 金币
    int money = static_cast<int>(input_money->value());

    // 轮数
    int level = static_cast<int>(input_level->value());

    // 页面
    std::map<Fl_Widget *, unsigned int> mp = {
        {group_resource, 0},
        {group_battle, 1},
        {group_lineup, 2},
        {group_spawn, 3},
        {group_others, 4},
    };
    unsigned int page = mp[tabs->value()];

    HKEY hKey;
    DWORD ret;
    ret = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                        0, KEY_SET_VALUE, &hKey);
    if (ret != ERROR_SUCCESS)
        ret = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                              0, nullptr, 0, KEY_SET_VALUE, nullptr, &hKey, nullptr);
    if (ret == ERROR_SUCCESS)
    {
        if (check_tooltips->value() == 1)
            RegSetValueExW(hKey, L"Language", 0, REG_SZ, (LPBYTE)&langEnglish, sizeof(langEnglish));
        else
            RegSetValueExW(hKey, L"Language", 0, REG_SZ, (LPBYTE)&langChinese, sizeof(langChinese));
        RegSetValueExW(hKey, L"ScaleFactor", 0, REG_DWORD, (LPBYTE)&scale, sizeof(scale));
        RegSetValueExW(hKey, L"Scheme", 0, REG_DWORD, (LPBYTE)&scheme, sizeof(scheme));
        RegSetValueExW(hKey, L"SpawnTypes", 0, REG_SZ, (LPBYTE)&zombies, sizeof(zombies));
        RegSetValueExW(hKey, L"SpawnMode", 0, REG_DWORD, (LPBYTE)&mode, sizeof(mode));
        RegSetValueExW(hKey, L"ValueSun", 0, REG_DWORD, (LPBYTE)&sun, sizeof(sun));
        RegSetValueExW(hKey, L"ValueMoney", 0, REG_DWORD, (LPBYTE)&money, sizeof(money));
        RegSetValueExW(hKey, L"ValueLevel", 0, REG_DWORD, (LPBYTE)&level, sizeof(level));
        RegSetValueExW(hKey, L"CurrentPage", 0, REG_DWORD, (LPBYTE)&page, sizeof(page));
        RegCloseKey(hKey);
    }
}

// TODO fl_utf8fromwc fl_utf8towc

std::string Window::utf8_encode(const std::wstring &wstr)
{
    if (wstr.empty())
        return std::string();
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), nullptr, 0, nullptr, nullptr);
    std::string str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, nullptr, nullptr);
    return str;
}

std::wstring Window::utf8_decode(const std::string &str)
{
    if (str.empty())
        return std::wstring();
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), nullptr, 0);
    std::wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
    return wstr;
}

void Window::cb_find_result(void *w, int result)
{
    ((Window *)w)->cb_find_result(result);
}

void Window::cb_find_result(int result)
{
    // 重新找到游戏时应用所有已选功能
    if (result != PVZ_NOT_FOUND && result != PVZ_OPEN_ERROR && result != PVZ_UNSUPPORTED)
        this->keep_selected_feature();

    // 某些版本只实现了部分功能
    if (result == PVZ_BETA_0_1_1_1014_EN)
    {
        check_tree_food->deactivate();
        input_wisdom_tree->deactivate();
        button_wisdom_tree->deactivate();
    }
    else
    {
        check_tree_food->activate();
        input_wisdom_tree->activate();
        button_wisdom_tree->activate();
    }

    this->result = result;
    cb_find_result_tooltip();
}

void Window::cb_find_result_tooltip(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_find_result_tooltip();
}

void Window::cb_find_result_tooltip()
{
    bool on = check_tooltips->value() == 1;

    switch (result)
    {
    case PVZ_BETA_0_1_1_1014_EN:
        game_status->copy_label("0.1.1.1014 英语测试版");
        game_status->copy_tooltip(on ? "0.1.1.1014 Beta (en)" : nullptr);
        break;
    case PVZ_BETA_0_9_9_1029_EN:
        game_status->copy_label("0.9.9.1029 英语测试版");
        game_status->copy_tooltip(on ? "0.9.9.1029 Beta (en)" : nullptr);
        break;
    case PVZ_1_0_0_1051_EN:
        game_status->copy_label("1.0.0.1051 英语原始版");
        game_status->copy_tooltip(on ? "1.0.0.1051 (en)" : nullptr);
        break;
    case PVZ_1_2_0_1065_EN:
        game_status->copy_label("1.2.0.1065 英语修复版");
        game_status->copy_tooltip(on ? "1.2.0.1065 (en)" : nullptr);
        break;
    case PVZ_1_0_4_7924_ES:
        game_status->copy_label("1.0.4.7924 西班牙语版");
        game_status->copy_tooltip(on ? "1.0.4.7924 (es)" : nullptr);
        break;
    case PVZ_1_0_7_3556_ES:
        game_status->copy_label("1.0.7.3556 西班牙语版");
        game_status->copy_tooltip(on ? "1.0.7.3556 (es)" : nullptr);
        break;
    case PVZ_1_0_7_3467_RU:
        game_status->copy_label("1.0.7.3467 俄罗斯语版");
        game_status->copy_tooltip(on ? "1.0.7.3467 (ru)" : nullptr);
        break;
    case PVZ_GOTY_1_2_0_1073_EN:
        game_status->copy_label("1.2.0.1073 英语年度版");
        game_status->copy_tooltip(on ? "1.2.0.1073 GOTY Origin (en)" : nullptr);
        break;
    case PVZ_GOTY_1_2_0_1096_EN:
        game_status->copy_label("1.2.0.1096 英语年度版");
        game_status->copy_tooltip(on ? "1.2.0.1096 GOTY Steam (en)" : nullptr);
        break;
    case PVZ_GOTY_1_2_0_1093_DE_ES_FR_IT:
        game_status->copy_label("1.2.0.1093 多国语言年度版");
        game_status->copy_tooltip(on ? "1.2.0.1093 GOTY Origin (de/es/fr/it)" : nullptr);
        break;
    case PVZ_GOTY_1_1_0_1056_ZH:
        game_status->copy_label("1.1.0.1056 粘度汗化版");
        game_status->copy_tooltip(on ? "1.1.0.1056 GOTY 2010 (zh)" : nullptr);
        if (!this->bad_version_warned)
        {
            this->bad_version_warned = true;
            fl_message_title("温馨提示");
            int c = fl_choice("这个版本的游戏存在着严重的问题，随时可能会崩溃。\n" //
                              "建议更换使用其他能正常运行的版本，现在去下载吗？",  //
                              "No", "Yes", 0);
            if (c == 1)
                ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/download/", //
                              nullptr, nullptr, SW_SHOWNORMAL);
        }
        break;
    case PVZ_GOTY_1_1_0_1056_JA:
        game_status->copy_label("1.1.0.1056 日语年度版");
        game_status->copy_tooltip(on ? "1.1.0.1056 GOTY (ja)" : nullptr);
        break;
    case PVZ_GOTY_1_1_0_1056_ZH_2012_06:
        game_status->copy_label("1.1.0.1056 年度加强版");
        game_status->copy_tooltip(on ? "1.1.0.1056 GOTY 2012 (zh)" : nullptr);
        break;
    case PVZ_GOTY_1_1_0_1056_ZH_2012_07:
        game_status->copy_label("1.1.0.1056 年度加强版");
        game_status->copy_tooltip(on ? "1.1.0.1056 GOTY 2012 (zh)" : nullptr);
        break;
    case PVZ_UNSUPPORTED:
        game_status->copy_label("不支持的游戏版本");
        game_status->copy_tooltip(on ? "Unsupported game version." : nullptr);
        break;
    case PVZ_OPEN_ERROR:
        game_status->copy_label("打开游戏进程出错");
        game_status->copy_tooltip(on ? "Error opening game process." : nullptr);
        break;
    case PVZ_NOT_FOUND:
    default:
        game_status->copy_label("没有找到游戏窗口");
        game_status->copy_tooltip(on ? "No game window was found." : nullptr);
        break;
    }

    if (result == PVZ_NOT_FOUND)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Run Plants vs. Zombies first."
                                         : "先打开运行植物大战僵尸游戏。");
    }
    else if (result == PVZ_OPEN_ERROR)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Try run Pt as administrator."
                                         : "建议用管理员权限运行修改器。");
    }
    else if (result == PVZ_UNSUPPORTED)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Contact author to add support."
                                         : "联系作者给这个版本添加支持。");
    }
    else if (result == PVZ_BETA_0_1_1_1014_EN)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Partial support for beta version."
                                         : "对早期测试版本仅提供有限功能支持，\n"
                                           "游戏对象的序号和名称未能完全对应。");
    }
    else if (result == PVZ_BETA_0_9_9_1029_EN)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Partial support for beta version."
                                         : "对测试版本仅提供有限的功能支持。");
    }
    else if (result == PVZ_GOTY_1_1_0_1056_ZH)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Replace this bad game version."
                                         : "换掉这个有严重问题的游戏版本。");
    }
    else
    {
        game_status_tip->copy_label("");
        game_status_tip->copy_tooltip(nullptr);

        SYSTEMTIME time_now;
        GetLocalTime(&time_now);
        if (time_now.wYear > 2009 && time_now.wMonth == 5 && time_now.wDay == 5)
        {
            game_status_tip->copy_label("🎂");
            game_status_tip->copy_tooltip("Plants vs. Zombies (May 5, 2009)");
        }
    }

    game_status->redraw();
    game_status_tip->redraw();
}

void Window::keep_selected_feature()
{
    std::vector<Fl_Check_Button *> check_buttons = {
        check_auto_collected,
        check_not_drop_loot,
        check_fertilizer,
        check_bug_spray,
        check_tree_food,
        check_chocolate,
        check_free_planting,
        check_placed_anywhere,
        check_fast_belt,
        check_lock_shovel,
        check_plant_invincible,
        check_plant_weak,
        check_zombie_invincible,
        check_zombie_weak,
        check_reload_instantly,
        check_mushroom_awake,
        check_stop_spawning,
        check_stop_zombies,
        check_lock_butter,
        check_no_crater,
        check_no_ice_trail,
        check_zombie_not_explode,
        check_no_fog,
        check_see_vase,
        check_background,
        check_readonly,
        check_limbo_page,
        check_lineup_mode, // 这个放在最后
    };

    if (check_unlock_sun_limit->value() == 1)
        check_unlock_sun_limit->do_callback();

    for (size_t i = 0; i < check_buttons.size(); i++)
    {
        if (check_buttons[i]->value() == 1)
            check_buttons[i]->do_callback();
    }
}

void Window::cb_mode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_mode();
}

void Window::cb_mode()
{
    if (choice_mode->value() == 0) // 冒险模式
        choice_adventure->activate();
    else
        choice_adventure->deactivate();

    cb_tooltips();
}

void Window::cb_load_lineup(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_load_lineup();
}

void Window::cb_load_lineup()
{
    import_lineup_list(false);
}

void Window::import_lineup_list(bool automatic)
{
    if (automatic)
    {
        wchar_t find_path[MAX_PATH] = {0};
        GetCurrentDirectoryW(MAX_PATH, find_path);
        wcscat_s(find_path, L"\\*");
        WIN32_FIND_DATA ffd;
        HANDLE hf;
        hf = FindFirstFileW(find_path, &ffd);
        if (hf != INVALID_HANDLE_VALUE)
        {
            do
            {
                std::wstring name = ffd.cFileName;
                if (name == L"." || name == L"..")
                    continue;
                std::wstring ext = name.substr(name.find_last_of(L".") + 1);
                if (ext == L"yml")
                {
                    import_lineup_list_file(name.c_str());
                    // std::wcout << L"导入阵型列表: " << name << std::endl;
                }
            } while (FindNextFileW(hf, &ffd) != 0);
            FindClose(hf);
        }
    }
    else
    {
        TCHAR szFileName[MAX_PATH];
        OPENFILENAME ofn;
        ZeroMemory(&ofn, sizeof(ofn));
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = nullptr;
        ofn.lpstrFilter = L"YAML(*.yml)\0*.yml\0";
        ofn.nFilterIndex = 1;
        ofn.lpstrFile = szFileName;
        ofn.lpstrFile[0] = '\0';
        ofn.nMaxFile = sizeof(szFileName);
        ofn.lpstrFileTitle = nullptr;
        ofn.nMaxFileTitle = 0;
        ofn.lpstrInitialDir = nullptr;
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
        if (GetOpenFileNameW(&ofn) == TRUE)
        {
#ifdef _DEBUG
            std::wcout << L"打开文件: " << std::wstring(szFileName) << std::endl;
#endif
            import_lineup_list_file(szFileName);
        }
    }

    if (this->lineups.empty())
        return;

    // 排序
    auto LessThan = [&](const Lineup &l1, const Lineup &l2)
    { return l1.weight < l2.weight; };
    std::sort(this->lineups.begin(), this->lineups.end(), LessThan);

    // 插入
    for (size_t i = 0; i < this->lineups.size(); i++)
    {
        uint32_t scene = static_cast<uint32_t>(this->lineups[i].scene);
        std::string name = this->lineups[i].lineup_name;

        while (choice_lineup_name[scene]->find_index(name.c_str()) != -1)
            name += " "; // 相同名字的在后面补空格

        choice_lineup_name[scene]->add(name.c_str());
        lineup_count[scene]++;
    }

    for (size_t i = 0; i < 6; i++)
        if (choice_lineup_name[i]->size() > 0)
            choice_lineup_name[i]->value(0);

    button_load_lineup->hide();
    cb_switch_lineup_scene();
}

void Window::import_lineup_list_file(std::wstring file)
{
    std::ifstream ifs(file.c_str());
    if (!ifs)
        return;

    std::vector<std::tuple<int, std::string>> err_lst;

    int line = 0;
    std::string str;
    while (std::getline(ifs, str))
    {
        line++;
        if (line == 1) // 第一行
        {
            if (str != "#! pvztoolkit")
                break;
        }
        else
        {
            if (str[0] == '#' || str.empty()) // 注释或者空行
            {
                continue;
            }
            else
            {
                std::regex re("\".*\": [a-zA-Z0-9+/=]{1,}");
                if (std::regex_match(str, re))
                {
                    size_t p = str.find_last_of(": ");
                    std::string name = str.substr(0 + 1, p - 3);
                    std::string code = str.substr(p + 1);
                    Lineup lineup(name, code);
                    if (lineup.OK())
                    {
                        this->lineups.push_back(lineup);
                    }
                    else
                    {
                        std::tuple err = {line, str};
                        err_lst.push_back(err);
                    }
                }
                else
                {
                    std::tuple err = {line, str};
                    err_lst.push_back(err);
                }
            }
        }
    }

    if (err_lst.size() > 0)
    {
        std::wstring title = file + L" " + L"阵型列表格式错误";
        std::wstring text;
        for (size_t i = 0; i < err_lst.size(); i++)
        {
            if (i > 11)
            {
                text += std::wstring() + L"\n" + L"（还有更多的没有显示……）";
                break;
            }
            auto [l, s] = err_lst[i];
            if (s.length() > 49)
                s = s.substr(0, 48) + " ...";
            text += std::wstring()                            //
                    + L"第 " + std::to_wstring(l) + L" 行： " //
                    + utf8_decode(s) + L"\n";                 //
        }
        fl_message_title(utf8_encode(title).c_str());
        fl_message(utf8_encode(text).c_str());
    }
}

void Window::cb_switch_lineup_scene(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_switch_lineup_scene();
}

void Window::cb_switch_lineup_scene()
{
    if (this->lineups.empty())
        return;

    for (size_t i = 0; i < 6; i++)
    {
        if (i == choice_scene->value())
            choice_lineup_name[i]->show();
        else
            choice_lineup_name[i]->hide();
    }

    cb_tooltips();
    cb_show_lineup_string();
}

void Window::cb_show_lineup_string(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_show_lineup_string();
}

void Window::cb_show_lineup_string()
{
    if (lineup_count[choice_scene->value()] == 0)
    {
        buffer_lineup_string->text("");
        return;
    }

    int index = 0;
    for (int i = 0; i < choice_scene->value(); i++)
        index += lineup_count[i];
    index += choice_lineup_name[choice_scene->value()]->value();

#ifdef _DEBUG
    std::cout << index << " " << this->lineups[index].lineup_name << std::endl;
#endif

    buffer_lineup_string->text(this->lineups[index].lineup_code.c_str());
}

void Window::cb_copy_lineup(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_copy_lineup();
}

void Window::cb_copy_lineup()
{
    Fl::copy(buffer_lineup_string->text(), buffer_lineup_string->length(), 1, Fl::clipboard_plain_text);
}

void Window::cb_paste_lineup(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_paste_lineup();
}

void Window::cb_paste_lineup()
{
    buffer_lineup_string->text("");
    Fl_Text_Editor::kf_paste(0, editor_lineup_string);

    std::string str = buffer_lineup_string->text();

    // 去掉不可见字符
    str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\v'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\f'), str.end());
    // 去掉首尾空格
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    // 去掉多余空格
    str = std::regex_replace(str, std::regex("( ){2,}"), " ");
    str = std::regex_replace(str, std::regex(", "), ",");
    str = std::regex_replace(str, std::regex(" ,"), ",");

    // 统一转成新格式
    Lineup lineup(str);
    str = lineup.Generate();

    buffer_lineup_string->text(str.c_str());
}

void Window::cb_spawn_mutex_0(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_spawn_mutex_0();
}

void Window::cb_spawn_mutex_0()
{
    if (check_zombie[0]->value() == 1 && limit_species)
        check_zombie[3]->value(0);
    cb_spawn_count_check();
}

void Window::cb_spawn_mutex_3(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_spawn_mutex_3();
}

void Window::cb_spawn_mutex_3()
{
    if (check_zombie[3]->value() == 1 && limit_species)
        check_zombie[0]->value(0);
    cb_spawn_count_check();
}

void Window::cb_spawn_count_check(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_spawn_count_check();
}

void Window::cb_spawn_count_check()
{
    int count = 1; // 普僵必出
    for (size_t i = 0; i < 20; i++)
        if ((spawn_type[i] != 19) && (spawn_type[i] != 20))
            count += check_zombie[i]->value() == 1 ? 1 : 0;
#ifdef _DEBUG
    std::wcout << L"出怪总数(包括普僵不包括雪人蹦极): " << count << std::endl;
#endif

    for (size_t i = 0; i < 20; i++)
    {
        if ((spawn_type[i] != 19) && (spawn_type[i] != 20))
        {
            if (limit_species && count >= 11) // 限制出怪类型总数
            {
                // 超限了, 把没选的停用
                if (check_zombie[i]->value() == 0)
                    check_zombie[i]->deactivate();
            }
            else
            {
                // 没超, 把所有停用的启用
                if (check_zombie[i]->active() == 0)
                    check_zombie[i]->activate();
            }
        }
    }
}

void Window::cb_clear_checked_zombies(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_clear_checked_zombies();
}

void Window::cb_clear_checked_zombies()
{
    for (size_t i = 0; i < 20; i++)
        check_zombie[i]->value(0);
    cb_spawn_count_check();
}

void Window::cb_disable_limit_species(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_disable_limit_species();
}

void Window::cb_disable_limit_species()
{
    if (limit_species)
    {
        limit_species = false;
        button_spawn_extra->replace(1, EMOJI("✅", "[启用限制]"));
    }
    else
    {
        limit_species = true;
        button_spawn_extra->replace(1, EMOJI("❎", "[取消限制]"));
    }

    button_spawn_extra->value(0);
    cb_spawn_count_check();
}

void Window::cb_switch_spawn_mode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_switch_spawn_mode();
}

void Window::cb_switch_spawn_mode()
{
    bool on = check_tooltips->value() == 1;

    switch (button_spawn_mode->value())
    {
    case 0: // 自然
        choice_giga_weight->deactivate();
        check_giga_limit->deactivate();
        button_set_spawn->copy_label("自然出怪 (游戏生成)");
        button_set_spawn->copy_tooltip(on ? "Natural (Game Generate)" : nullptr);
        break;

    case 1: // 极限
    default:
        choice_giga_weight->deactivate();
        check_giga_limit->activate();
        button_set_spawn->copy_label("极限出怪 (均匀填充)");
        button_set_spawn->copy_tooltip(on ? "Extreme (Filling Evenly)" : nullptr);
        break;

    case 2: // 模拟
        choice_giga_weight->activate();
        check_giga_limit->activate();
        button_set_spawn->copy_label("模拟出怪 (加权随机)");
        button_set_spawn->copy_tooltip(on ? "Simulate (Weighted Random)" : nullptr);
        break;
    }
}

void Window::cb_open_file(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_open_file();
}

void Window::cb_open_file()
{
    TCHAR szFileName[MAX_PATH];

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = nullptr;
    // hInstance
    ofn.lpstrFilter = L"PAK (*.pak)\0*.pak\0";
    // lpstrCustomFilter
    // nMaxCustFilter
    ofn.nFilterIndex = 1;
    ofn.lpstrFile = szFileName;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFileName);
    ofn.lpstrFileTitle = nullptr;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = nullptr;
    // lpstrTitle
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    // nFileOffset
    // nFileExtension
    // lpstrDefExt
    // lCustData
    // lpfnHook
    // lpTemplateName
    // pvReserved
    // dwReserved
    // FlagsEx

    if (GetOpenFileNameW(&ofn) == TRUE)
    {
#ifdef _DEBUG
        std::wcout << L"打开文件: " << std::wstring(szFileName) << std::endl;
#endif
        std::string file_path = utf8_encode(std::wstring(szFileName));
        input_file->value(file_path.c_str());

        if (input_dir->size() == 0)
        {
            wchar_t self_path[MAX_PATH];
            DWORD length = GetModuleFileNameW(nullptr, self_path, MAX_PATH);
            if (length != 0)
            {
                std::string dir_path = utf8_encode(std::wstring(self_path));
                dir_path = dir_path.substr(0, dir_path.find_last_of("\\") + 1) //
                           + "extract_" + std::to_string(std::time(nullptr));
                input_dir->value(dir_path.c_str());
            }
        }
    }
}

void Window::cb_open_dir(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_open_dir();
}

void Window::cb_open_dir()
{
    TCHAR szPathName[MAX_PATH];

    BROWSEINFO bi;
    ZeroMemory(&bi, sizeof(bi));
    bi.hwndOwner = nullptr;
    bi.pidlRoot = nullptr;
    // pszDisplayName
    bi.lpszTitle = L"选择要打包的文件夹：";
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI | BIF_NONEWFOLDERBUTTON;
    bi.lpfn = nullptr;
    // lParam
    // iImage

    LPITEMIDLIST lpDlist;
    lpDlist = SHBrowseForFolder(&bi);
    if (lpDlist != NULL)
    {
        if (SHGetPathFromIDList(lpDlist, szPathName) == TRUE)
        {
#ifdef _DEBUG
            std::wcout << L"选择文件夹: " << std::wstring(szPathName) << std::endl;
#endif
            input_dir->value(utf8_encode(std::wstring(szPathName)).c_str());
        }
        CoTaskMemFree(lpDlist);
    }
}

void Window::cb_scheme(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_scheme();
}

void Window::cb_scheme()
{
    Fl::scheme(choice_scheme->text());
    cb_tooltips();
}

void Window::cb_document(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_document();
}

void Window::cb_document()
{
    ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", nullptr, nullptr, SW_SHOWNORMAL);
}

void Window::cb_tooltips(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_tooltips();
}

void Window::cb_tooltips()
{
    static std::vector<std::string> vstr_modes;
    if (vstr_modes.size() == 0)
    {
        for (size_t i = 0; i < 73; i++)
            vstr_modes.push_back("[" + std::to_string(i) + "]" + " " + modes[i]);
    }

    static std::vector<std::string> vstr_rows;
    if (vstr_rows.size() == 0)
    {
        vstr_rows.push_back("All Rows");
        vstr_rows.push_back("1st Row");
        vstr_rows.push_back("2nd Row");
        vstr_rows.push_back("3rd Row");
        vstr_rows.push_back("4th Row");
        vstr_rows.push_back("5th Row");
        vstr_rows.push_back("6th Row");
    }

    static std::vector<std::string> vstr_cols;
    if (vstr_cols.size() == 0)
    {
        vstr_cols.push_back("All Columns");
        vstr_cols.push_back("1st Column");
        vstr_cols.push_back("2nd Column");
        vstr_cols.push_back("3rd Column");
        vstr_cols.push_back("4th Column");
        vstr_cols.push_back("5th Column");
        vstr_cols.push_back("6th Column");
        vstr_cols.push_back("7th Column");
        vstr_cols.push_back("8th Column");
        vstr_cols.push_back("9th Column");
    }

    static std::vector<std::string> vstr_plants;
    if (vstr_plants.size() == 0)
        for (size_t i = 0; i < 48; i++)
            vstr_plants.push_back("[" + std::to_string(i) + "]" + " " + plants[i]);

    static std::vector<std::string> vstr_zombies;
    if (vstr_zombies.size() == 0)
        for (size_t i = 0; i < 33; i++)
            vstr_zombies.push_back("[" + std::to_string(i) + "]" + " " + zombies[i]);

    static std::vector<std::string> vstr_items;
    if (vstr_items.size() == 0)
    {
        vstr_items.push_back("Plants");
        vstr_items.push_back("Zombies");
        vstr_items.push_back("Ladders");
        vstr_items.push_back("Graves");
        vstr_items.push_back("Rakes");
    }

    static std::vector<std::string> vstr_slots;
    if (vstr_slots.size() == 0)
    {
        vstr_slots.push_back("1st Seed");
        vstr_slots.push_back("2nd Seed");
        vstr_slots.push_back("3rd Seed");
        vstr_slots.push_back("4th Seed");
        vstr_slots.push_back("5th Seed");
        vstr_slots.push_back("6th Seed");
        vstr_slots.push_back("7th Seed");
        vstr_slots.push_back("8th Seed");
        vstr_slots.push_back("9th Seed");
        vstr_slots.push_back("10th Seed");
    }

    static std::vector<std::string> vstr_scenes;
    if (vstr_scenes.size() == 0)
    {
        vstr_scenes.push_back("Day");
        vstr_scenes.push_back("Night");
        vstr_scenes.push_back("Pool");
        vstr_scenes.push_back("Fog");
        vstr_scenes.push_back("Roof");
        vstr_scenes.push_back("Moon");
    }

    static std::vector<std::string> vstr_debugs;
    if (vstr_debugs.size() == 0)
    {
        vstr_debugs.push_back("Off");
        vstr_debugs.push_back("Spawning");
        vstr_debugs.push_back("Music");
        vstr_debugs.push_back("Memory");
        vstr_debugs.push_back("Collision");
    }

    bool on = check_tooltips->value() == 1;

    check_unlock_sun_limit->copy_tooltip(on ? "Disable Upper Limit" : "去除上限");
    input_sun->copy_tooltip("0 ~ 9990");
    button_sun->copy_tooltip(on ? "Sun" : nullptr);
    input_money->copy_tooltip("0 ~ 99999");
    button_money->copy_tooltip(on ? "Coins" : nullptr);
    check_auto_collected->copy_tooltip(on ? "Automatic Collected" : nullptr);
    check_not_drop_loot->copy_tooltip(on ? "Not Drop Loot" : nullptr);
    check_fertilizer->copy_tooltip(on ? "Unlimited Fertilizer" : nullptr);
    check_bug_spray->copy_tooltip(on ? "Unlimited Bug Spray" : nullptr);
    check_tree_food->copy_tooltip(on ? "Unlimited Tree Food" : nullptr);
    check_chocolate->copy_tooltip(on ? "Unlimited Chocolate" : nullptr);
    input_wisdom_tree->copy_tooltip("0 ~ 1000");
    button_wisdom_tree->copy_tooltip(on ? "Feet Tall" : nullptr);
    check_free_planting->copy_tooltip(on ? "Free Planting" : nullptr);
    check_placed_anywhere->copy_tooltip(on ? "Placed Anywhere" : nullptr);
    check_fast_belt->copy_tooltip(on ? "Seamless Conveyor Belt" : nullptr);
    check_lock_shovel->copy_tooltip(on ? "Shovel Continuously" : nullptr);
    choice_mode->copy_tooltip(on ? vstr_modes[choice_mode->value()].c_str() : nullptr);
    choice_adventure->copy_tooltip(on ? choice_adventure->text(choice_adventure->value()) : nullptr);
    button_mix->copy_tooltip(on ? "Modify Mode" : nullptr);
    input_level->copy_tooltip("0 ~ 10000000");
    button_level->copy_tooltip(on ? "Endless Rounds" : nullptr);
    button_unlock->copy_tooltip(on ? "Get Gold Sunflower Trophy" : "解锁黄金向日葵奖杯");
    button_direct_win->copy_tooltip(on ? "Level Complete" : nullptr);

    choice_row->copy_tooltip(on ? vstr_rows[choice_row->value()].c_str() : nullptr);
    choice_col->copy_tooltip(on ? vstr_cols[choice_col->value()].c_str() : nullptr);
    choice_plant->copy_tooltip(on ? vstr_plants[choice_plant->value()].c_str() : nullptr);
    choice_zombie->copy_tooltip(on ? vstr_zombies[choice_zombie->value()].c_str() : nullptr);
    button_put_plant->copy_tooltip(on ? "Place Plant" : nullptr);
    check_imitater->copy_tooltip(on ? "Imitater" : nullptr);
    button_put_zombie->copy_tooltip(on ? "Place Zombie" : nullptr);
    button_put_ladder->copy_tooltip(on ? "Place Ladder" : nullptr);
    button_put_grave->copy_tooltip(on ? "Place Grave" : nullptr);
    button_put_rake->copy_tooltip(on ? "Place Rake" : nullptr);
    button_lawn_mower->copy_tooltip(on ? "Lawn Mowers" : nullptr);
    choice_item->copy_tooltip(on ? vstr_items[choice_item->value()].c_str() : nullptr);
    button_clear->copy_tooltip(on ? "Clear" : nullptr);
    check_plant_invincible->copy_tooltip(on ? "Plant Invincible" : nullptr);
    check_plant_weak->copy_tooltip(on ? "Plant Weak" : nullptr);
    check_zombie_invincible->copy_tooltip(on ? "Zombie Invincible" : nullptr);
    check_zombie_weak->copy_tooltip(on ? "Zombie Weak" : nullptr);
    check_reload_instantly->copy_tooltip(on ? "Reload Instantly" : nullptr);
    check_mushroom_awake->copy_tooltip(on ? "Mushroom Awake" : nullptr);
    check_stop_spawning->copy_tooltip(on ? "Spawning Paused" : nullptr);
    check_stop_zombies->copy_tooltip(on ? "Stay In Place" : nullptr);
    check_lock_butter->copy_tooltip(on ? "Always Butter" : nullptr);
    check_no_crater->copy_tooltip(on ? "No Crater" : nullptr);
    check_no_ice_trail->copy_tooltip(on ? "No Ice Trail" : nullptr);
    check_zombie_not_explode->copy_tooltip(on ? "Zombies Never Explode" : nullptr);

    choice_slot->copy_tooltip(on ? vstr_slots[choice_slot->value()].c_str() : nullptr);
    if (choice_seed->value() == -1)
        choice_seed->copy_tooltip(nullptr);
    else
        choice_seed->copy_tooltip(on ? vstr_plants[choice_seed->value()].c_str() : nullptr);
    button_seed->copy_tooltip(on ? "Replace Seed" : nullptr);
    check_seed_imitater->copy_tooltip(on ? "Imitater" : nullptr);
    check_lineup_mode->copy_tooltip(on ? "Lineup Mode Shortcut" : nullptr);
    button_auto_ladder->copy_tooltip(on ? "Smart Laddering" : nullptr);
    button_put_lily_pad->copy_tooltip(on ? "Lily Pad On Pool" : nullptr);
    button_put_flower_pot->copy_tooltip(on ? "Flower Pot On Roof" : nullptr);
    button_reset->copy_tooltip(on ? "Reset Scene" : nullptr);
    choice_scene->copy_tooltip(on ? vstr_scenes[choice_scene->value()].c_str() : nullptr);
    button_load_lineup->copy_tooltip(on ? "Load Lineup List File (***.yml)" : nullptr);
    for (size_t i = 0; i < 6; i++)
        choice_lineup_name[i]->copy_tooltip(on ? "(Lineup Name)" : nullptr);
    button_get_lineup->copy_tooltip(on ? "Get Lineup Code" : nullptr);
    button_copy_lineup->copy_tooltip(on ? "Copy / Export" : nullptr);
    button_paste_lineup->copy_tooltip(on ? "Paste / Import" : nullptr);
    button_set_lineup->copy_tooltip(on ? "Apply Current Build" : nullptr);
    editor_lineup_string->copy_tooltip(on ? "(Lineup Code)" : "(阵型代码)");
    button_capture->copy_tooltip(on ? "Screenshot To Clipboard" : "截图到剪贴板");

    for (size_t i = 0; i < 20; i++)
    {
        std::string z = "[" + std::to_string(spawn_type[i]) + "]" //
                        + " " + zombies[spawn_type[i]];
        check_zombie[i]->copy_tooltip(on ? z.c_str() : nullptr);
    }
    choice_giga_weight->copy_tooltip(on ? "GigaGargantuar\'s weight in non-huge waves."
                                        : "非旗帜波的红眼僵尸随机权重。");
    check_giga_limit->copy_tooltip(on ? "No GigaGargantuar in 11th ~ 19th waves."
                                      : "第 11 ~ 19 波不出红眼僵尸。");
    button_set_spawn->copy_tooltip(on ? "Right click to change spawning mode."
                                      : "右键切换出怪列表生成方法。");

    choice_music->copy_tooltip(on ? choice_music->text(choice_music->value()) : nullptr);
    button_music->copy_tooltip(on ? "Background Music" : nullptr);
    button_userdata->copy_tooltip(on ? "Userdata Folder" : nullptr);
    check_no_fog->copy_tooltip(on ? "Clear Fog" : nullptr);
    check_see_vase->copy_tooltip(on ? "Transparent Vase" : nullptr);
    check_background->copy_tooltip(on ? "Enable Background Running" : nullptr);
    check_readonly->copy_tooltip(on ? "Disable Delete/Save Userdata" : nullptr);
    button_file->copy_tooltip(on ? "Choose File" : nullptr);
    input_file->copy_tooltip(on ? "(File Path)" : "(文件路径)");
    button_unpack->copy_tooltip(on ? "Extract" : nullptr);
    button_dir->copy_tooltip(on ? "Choose Folder" : nullptr);
    input_dir->copy_tooltip(on ? "(Folder Path)" : "(文件夹路径)");
    button_pack->copy_tooltip(on ? "Pack" : nullptr);
    choice_debug->copy_tooltip(on ? vstr_debugs[choice_debug->value()].c_str() : nullptr);
    button_debug->copy_tooltip(on ? "Debug" : nullptr);
    choice_speed->copy_tooltip(on ? choice_speed->text(choice_speed->value()) : nullptr);
    button_speed->copy_tooltip(on ? "Speed" : nullptr);
    check_limbo_page->copy_tooltip(on ? "Show Limbo Page" : nullptr);
    choice_scheme->copy_tooltip(on ? choice_scheme->text(choice_scheme->value()) : nullptr);
    check_tooltips->copy_tooltip("English Tooltips");
    button_document->copy_tooltip(on ? "Document" : nullptr);
    button_about->copy_tooltip(on ? "About ..." : nullptr);

    box_mask_resource->copy_tooltip(on ? "Resources" : nullptr);
    box_mask_battle->copy_tooltip(on ? "Battlefield" : nullptr);
    box_mask_lineup->copy_tooltip(on ? "Setups" : nullptr);
    box_mask_spawn->copy_tooltip(on ? "Spawning" : nullptr);
    box_mask_others->copy_tooltip(on ? "Others" : nullptr);

    cb_find_result_tooltip();

    // 触发重新显示
    if (on && this->shown())
    {
        HWND me = fl_xid(this);
        POINT point = {0, 0};
        SendMessageW(me, WM_MOUSEMOVE, 0, MAKELONG(point.x, point.y));
        GetCursorPos(&point);
        ScreenToClient(me, &point);
        SendMessageW(me, WM_MOUSEMOVE, 0, MAKELONG(point.x, point.y));
    }

    // 顺便更新标题

    // 96   100%
    // 120  125%
    // 144  150%
    // 168  175%
    // 192  200%
    int dpi = 96;
    HDC dc = GetDC(nullptr);
    if (dc != nullptr)
    {
        // int virtual_width = GetDeviceCaps(dc, HORZRES);
        // int physical_width = GetDeviceCaps(dc, DESKTOPHORZRES);
        // dpi = 96 * physical_width / virtual_width;
        int dpi_x = GetDeviceCaps(dc, LOGPIXELSX);
        int dpi_y = GetDeviceCaps(dc, LOGPIXELSY);
        dpi = (dpi_x + dpi_y) / 2;
        ReleaseDC(nullptr, dc);
    }
    // std::cout << "dpi: " << dpi << std::endl;

    std::string title;
    if (dpi <= 96)
        title = on ? "Plants vs. Zombies All Version Toolkit"
                   : "PvZ Toolkit - 植物大战僵尸全版本辅助工具";
    else if (dpi <= 120)
        title = on ? "Plants vs. Zombies Toolkit"
                   : "植物大战僵尸全版本辅助工具";
    else
        title = on ? "PvZ Toolkit"
                   : "植物大战僵尸辅助";
    this->copy_label(title.c_str());
}

void Window::cb_about(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_about();
}

void Window::cb_about()
{
    std::string version_full = std::string()             //
                               + VERSION_NAME            //
                               + " "                     //
                               + "("                     //
                               + TOSTRING(VERSION_BUILD) //
                               + ")";                    //

    // "Sep  1 2021"
    //  0123456789A
    std::string date = std::string(__DATE__);
    std::string time = std::string(__TIME__);
    if (date[4] == ' ')
        date[4] = '0';
    char s_month[4] = {date[0], date[1], date[2], 0};
    const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    int month = (strstr(month_names, s_month) - month_names) / 3 + 1;
    std::string build_date = std::string()                                     //
                             + date[7] + date[8] + date[9] + date[10]          //
                             + "/"                                             //
                             + (month < 10 ? "0" : "") + std::to_string(month) //
                             + "/"                                             //
                             + date[4] + date[5];                              //
    std::string build_date_time = build_date + " " + time;

    std::string text = std::string()                                              //
                       + "植物大战僵尸辅助工具" + "\n"                            //
                       + "Plants vs. Zombies Toolkit" + "\n"                      //
                       + "\n"                                                     //
                       + "官方网站：" + "\t" + "https://pvz.lmintlcx.com/" + "\n" //
                       + "\n"                                                     //
                       + "发行版本：" + "\t" + version_full + "\n"                //
                       + "编译时间：" + "\t" + build_date_time + "\n"             //
                       + "版权所有：" + "\t" + "© 2020~2022 L.Mint. LCX" + "\n"   //
                       + "\n"                                                     //
                       + "复刻起源：" + "\t" + "PVZ Helper 1.8.7" + "\n"          //
                       + "依赖项目：" + "\t" + "FLTK 1.4 + zlib 1.2.12" + "\n"    //
                       + "鸣谢名单：" + "\t" + "kmtohoem 63enjoy 273.15K" + "\n"; //

    fl_message_title("关于 PvZ Toolkit");
    fl_message(text.c_str());
}

} // namespace Pt
