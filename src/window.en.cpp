
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

const char *zombies_s[] =
    {
        "~",
        "Flag ~",
        "Conehead ~",
        "Pole Vaulting ~",
        "Buckethead ~",
        "Newspaper ~",
        "Screen Door ~",
        "Football ~",
        "Dancing ~",
        "Backup Dancer",
        "Ducky Tube ~",
        "Snorkel ~",
        "Zomboni",
        "~ Bobsled Team",
        "Dolphin Rider ~",
        "Jack-in-the-Box ~",
        "Balloon ~",
        "Digger ~",
        "Pogo ~",
        "~ Yeti",
        "Bungee ~",
        "Ladder ~",
        "Catapult ~",
        "Gargantuar",
        "Imp",
        "Dr. Zomboss",
        "Peashooter ~",
        "Wall-nut ~",
        "Jalapeno ~",
        "Gatling Pea ~",
        "Squash ~",
        "Tall-nut ~",
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
        "Unsodded (FC)",
        "Big Time",
        "Art Challenge Sunflower",
        "Air Raid",
        "Ice Level",
        "Zen Garden (FC)",
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

SpawnTable::SpawnTable(int X, int Y, int W, int H, const char *L = 0)
    : Fl_Table(X, Y, W, H, L)
{
    rows(ROWS);
    row_header(1);
    row_header_width(75 + 120);
    row_height_all(18);
    row_resize(0);
    cols(COLS);
    col_header(1);
    col_header_height(18 + 3);
    col_width_all(35);
    col_width(20, 35 + 25);
    col_resize(0);
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

void SpawnTable::draw_row_header(const char *s, int X, int Y, int W, int H)
{
    fl_push_clip(X, Y, W, H);
    fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
    fl_color(FL_BLACK);
    fl_draw(s, X, Y, W, H, FL_ALIGN_LEFT);
    fl_pop_clip();
}

void SpawnTable::draw_col_header(const char *s, int X, int Y, int W, int H)
{
    fl_push_clip(X, Y, W, H);
    fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, col_header_color());
    fl_color(FL_BLACK);
    fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
    fl_pop_clip();
}

void SpawnTable::draw_data(const char *s, int X, int Y, int W, int H, Fl_Color C)
{
    fl_push_clip(X, Y, W, H);
    // 背景
    fl_color(C); // fl_color(FL_WHITE);
    fl_rectf(X, Y, W, H);
    // 数据
    fl_color(FL_GRAY0);
    fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
    // 边框
    fl_color(color());
    fl_rect(X, Y, W, H);
    fl_pop_clip();
}

void SpawnTable::draw_cell(TableContext context, int ROW = 0, int COL = 0, //
                           int X = 0, int Y = 0, int W = 0, int H = 0)
{
    static char s[100];
    Fl_Color c = FL_WHITE;
    std::string z;
    int Ys = 0;
    for (int r = 0; r < ROW; r++)
        if (data[r][20 + 1 - 1] == 0)
            Ys += 18;

    switch (context)
    {
    case CONTEXT_STARTPAGE:
        fl_font(FL_FREE_FONT + 1, 13);
        return;
    case CONTEXT_COL_HEADER:
        sprintf_s(s, "%i", COL + 1);
        if (COL == (20 + 1 - 1))
        {
            std::string total_str = "(" + std::to_string(total) + ")";
            sprintf_s(s, "%s", total_str.c_str());
        }
        draw_col_header(s, X, Y, W, H);
        return;
    case CONTEXT_ROW_HEADER:
        if (data[ROW][20 + 1 - 1] == 0)
            break;
        z = "[" + std::to_string(ROW) + "]" + " " + zombies[ROW];
        sprintf_s(s, "%s", z.c_str());
        draw_row_header(s, X, Y - Ys, W, H);
        return;
    case CONTEXT_CELL:
        if (data[ROW][20 + 1 - 1] == 0)
            break;
        sprintf_s(s, "%i", data[ROW][COL]);
        if (COL == (20 + 1 - 1))
            c = 0xffffff00u - 0x01010100u * (min(data[ROW][COL], 300) * 0xffu / 500);
        else if (COL == (10 - 1) || COL == (20 - 1))
            c = 0xfaf0fa00u - 0x01000100u * (min(data[ROW][COL], 20) * 0xfau / 30);
        else
            c = 0xffffff00u - 0x01000100u * (min(data[ROW][COL], 20) * 0xffu / 30);
        draw_data(s, X, Y - Ys, W, H, c);
        return;
    default:
        return;
    }
}

Window::Window(int width, int height, const char *title)
    : Fl_Window(width, height, title)
{
    // int w = width;
    // int h = height;
    // 95*4+10*2+10*(4+1)=450
    // 25*6+10*2+10*(6+1)+30=270

    int w = 450 + 50 * 4; // 窗口宽度
    int h = 270;          // 窗口高度
    int m = 10;           // 控件边距
    int th = 30;          // 选项卡高度
    int iw = 95 + 50;     // 控件宽度 (1/4)
    int ih = 25;          // 控件高度 (1/6)

    int x = m + m;      // 第一个控件的 x 坐标
    int y = m + th + m; // 第一个控件的 y 坐标

    // (4 列的情况下) 根据列数返回 x 坐标
    auto c = [=](int col) -> int {
        return x + (iw + m) * (col - 1);
    };

    // (6 行的情况下) 根据行数返回 y 坐标
    auto r = [=](int row) -> int {
        return y + (ih + m) * (row - 1);
    };

    // 标题栏图标
    extern HINSTANCE fl_display;
    this->icon((const void *)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));

    // 位置大小标签
    // resizable(this);
    this->size(w, h);
    {
        tabs = new Fl_Tabs(m, m, w - m * 2, h - m * 2);
        {
            group_resource = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Resources");
            {
                input_sun = new Fl_Value_Input(c(1) + 30, r(1), iw - 40, ih, "");
                button_sun = new Fl_Button(c(2) + 30 - 40, r(1), iw - 50, ih, "Set Sun");
                input_money = new Fl_Value_Input(c(1) + 30, r(2), iw - 40, ih, "10x");
                button_money = new Fl_Button(c(2) + 30 - 40, r(2), iw - 50, ih, "Set Money");
                check_auto_collect = new Fl_Check_Button(c(1), r(3), iw, ih, "Auto Collect");
                check_no_falling = new Fl_Check_Button(c(2), r(3), iw, ih, "Zombie No Drop");
                check_fertilizer = new Fl_Check_Button(c(3) - 40, r(1), iw + 20, ih, "Unlimited Fertilizer");
                check_bug_spray = new Fl_Check_Button(c(4) - 20, r(1), iw + 20, ih, "Unlimited Bug Spray");
                check_chocolate = new Fl_Check_Button(c(3) - 40, r(2), iw + 20, ih, "Unlimited Chocolate");
                check_tree_food = new Fl_Check_Button(c(4) - 20, r(2), iw + 20, ih, "Unlimited Tree Food");
                input_wisdom_tree = new Fl_Value_Input(c(3) + 20, r(3), iw - 20 - 20, ih, "");
                button_wisdom_tree = new Fl_Button(c(4) - 20, r(3), iw + 20, ih, "Wisdom Tree Height");
                check_free_planting = new Fl_Check_Button(c(1), r(4), iw, ih, "Seeds Free Use");
                check_planting_anywhere = new Fl_Check_Button(c(2), r(4), iw, ih, "Putting Anywhere");
                check_fast_belt = new Fl_Check_Button(c(3), r(4), iw, ih, "Belt Continuously");
                check_lock_shovel = new Fl_Check_Button(c(4), r(4), iw, ih, "Lock Shovel");
                choice_slot = new Fl_Choice_(c(1), r(5), iw - 10, ih, "");
                choice_seed = new Fl_Choice_(c(2) - 10, r(5), iw + 10 + 40, ih, "");
                check_seed_imitater = new Fl_Check_Button(c(3) + 40, r(5), iw - 40, ih, "Imitater");
                button_seed = new Fl_Button(c(4), r(5), iw, ih, "Change Seed");
                choice_music = new Fl_Choice_(c(1), r(6), iw + 45, ih, "");
                button_music = new Fl_Button(c(2) + 45, r(6), iw - 45, ih, "Set Music");
                input_level = new Fl_Value_Input(c(3) + 40, r(6), iw - 40, ih, "2x");
                button_level = new Fl_Button(c(4), r(6), iw, ih, "Endless Rounds");
            }
            group_resource->end();

            group_battle = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Battlefield");
            {
                choice_row = new Fl_Choice_(c(1), r(1), iw - 20, ih, "");
                choice_col = new Fl_Choice_(c(1), r(2), iw - 20, ih, "");
                choice_plant = new Fl_Choice_(c(2) - 20, r(1), iw + 20 + 60, ih, "");
                choice_zombie = new Fl_Choice_(c(2) - 20, r(2), iw + 20 + 60, ih, "");
                button_put_plant = new Fl_Button(c(3) + 60, r(1), iw - 60 + 30, ih, "Plant");
                button_put_zombie = new Fl_Button(c(3) + 60, r(2), iw - 60 + 30, ih, "Zombie");
                check_imitater = new Fl_Check_Button(c(4) + 30, r(1), iw - 30, ih, "Imitater");
                button_put_grave = new Fl_Button(c(4) + 30, r(2), iw - 30, ih, "Grave");
                button_direct_win = new Fl_Button(c(1), r(3), iw - 20, ih, "Level Complete");
                choice_item = new Fl_Choice_(c(2) - 20, r(3), iw + 20 - 20, ih, "");
                button_clear = new Fl_Button(c(2) + iw - 20 + m, r(3), iw - 75, ih, "Clear");
                button_put_ladder = new Fl_Button(c(3) + 60, r(3), iw - 60 + 30, ih, "Ladder");
                button_auto_ladder = new Fl_Button(c(4) + 30, r(3), iw - 30, ih, "Auto Ladder");
                check_plant_invincible = new Fl_Check_Button(c(1), r(4), iw, ih, "Plant Invincible");
                check_plant_weak = new Fl_Check_Button(c(2), r(4), iw, ih, "Plant Weak");
                check_zombie_invincible = new Fl_Check_Button(c(3), r(4), iw, ih, "Zombie Invincible");
                check_zombie_weak = new Fl_Check_Button(c(4), r(4), iw, ih, "Zombie Weak");
                check_reload_instantly = new Fl_Check_Button(c(1), r(5), iw, ih, "Reload Instantly");
                check_mushroom_awake = new Fl_Check_Button(c(2), r(5), iw, ih, "Mushroom Awake");
                check_stop_spawning = new Fl_Check_Button(c(3), r(5), iw, ih, "Stop Spawning");
                check_stop_zombies = new Fl_Check_Button(c(4), r(5), iw, ih, "Stop Zombies");
                check_lock_butter = new Fl_Check_Button(c(1), r(6), iw, ih, "Lock Butter");
                check_no_crater = new Fl_Check_Button(c(2), r(6), iw, ih, "No Crater");
                check_no_ice_trail = new Fl_Check_Button(c(3), r(6), iw, ih, "No Ice Trail");
                check_zombie_not_explode = new Fl_Check_Button(c(4), r(6), iw, ih, "Never Explode");
            }
            group_battle->end();

            group_spawn = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Spawning");
            {
                int tmp[20] = {2, 3, 4, 5,      //
                               6, 7, 8, 11,     //
                               12, 14, 15, 16,  //
                               17, 18, 19, 20,  //
                               21, 22, 23, 32}; //
                memcpy(spawn_type, tmp, sizeof(tmp));
                for (size_t row = 0; row < 5; row++)
                    for (size_t col = 0; col < 4; col++)
                        check_zombie[row * 4 + col] = new Fl_Check_Button(c(col + 1), r(row + 1), iw, ih, "");
                button_show_details = new Fl_Button(c(1), r(6), iw, ih, "Show Details");
                check_limit_count = new Fl_Check_Button(c(2), r(6), iw, ih, "Limit Species");
                button_internal_spawn = new Fl_Button(c(3), r(6), iw, ih, "Built-in Generate");
                button_customize_spawn = new Fl_Button(c(4), r(6), iw, ih, "Filling Evenly");
            }
            group_spawn->end();

            group_others = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Others");
            {
                choice_mode = new Fl_Choice_(c(1), r(1), iw + m + iw - 20, ih, "");
                button_mix = new Fl_Button(c(3) - 20, r(1), iw + 20 - 50, ih, "Modify Mode");
                button_userdata = new Fl_Button(c(4) - 30, r(1), iw + 30, ih, "Open Userdata Folder");
                check_no_fog = new Fl_Check_Button(c(1), r(2), iw - 50, ih, "Clear Fog");
                check_see_vase = new Fl_Check_Button(c(2) - 50, r(2), iw - 50, ih, "See Vase");
                check_background = new Fl_Check_Button(c(3) - 100, r(2), iw + 25, ih, "Background Running");
                check_readonly = new Fl_Check_Button(c(4) - 75, r(2), iw + 75, ih, "Disable Delete/Save Userdata");
                button_file = new Fl_Button(c(1), r(3), iw - 30, ih, "Choose File");
                input_file = new Fl_Input(c(2) - 30, r(3), iw + 30 + m + iw + 45, ih, "");
                button_unpack = new Fl_Button(c(4) + 45, r(3), iw - 45, ih, "Extract");
                button_dir = new Fl_Button(c(1), r(4), iw - 30, ih, "Choose Folder");
                input_dir = new Fl_Input(c(2) - 30, r(4), iw + 30 + m + iw + 45, ih, "");
                button_pack = new Fl_Button(c(4) + 45, r(4), iw - 45, ih, "Pack");
                choice_debug = new Fl_Choice_(c(1), r(5), iw - 30, ih, "");
                button_debug = new Fl_Button(c(2) - 30, r(5), 110, ih, "Debug Mode");
                check_show_hidden_games = new Fl_Check_Button(c(3) + 35, r(5), 265, ih, "Show Hidden Games (Limbo Page)");
                button_download = new Fl_Button(c(1), r(6), iw, ih, "Download PvZ");
                button_update = new Fl_Button(c(2), r(6), iw, ih, "Check Updates");
                button_about = new Fl_Button(c(4), r(6), iw, ih, "About ...");
            }
            group_others->end();
        }
        tabs->end();
        game_status = new Fl_Box(320, 12, 300, 25, "");
        game_status_tooltip = new Fl_Box(630, 12, 10, 25, "");
    }
    this->end();

    window_spawn = new Fl_Double_Window(860 + 120, 640, "Spawning Counting");
    {
        table_spawn = new SpawnTable(10, 10, 860 + 120 - 20, 640 - 20);
        button_update_details = new Fl_Button(10, 10, 75 + 120, 18 + 3, "↻");
    }
    window_spawn->end();

    // 默认值

    input_sun->value(8000);
    input_sun->bounds(0, 9990);

    input_money->value(80000);
    input_money->bounds(0, 99999);

    input_wisdom_tree->value(1000);
    input_wisdom_tree->bounds(0, 99999);

    choice_slot->add("1st Slot");
    choice_slot->add("2nd Slot");
    choice_slot->add("3rd Slot");
    choice_slot->add("4th Slot");
    choice_slot->add("5th Slot");
    choice_slot->add("6th Slot");
    choice_slot->add("7th Slot");
    choice_slot->add("8th Slot");
    choice_slot->add("9th Slot");
    choice_slot->add("10th Slot");
    choice_slot->value(0);

    for (size_t i = 0; i < 48; i++)
    {
        std::string p = "[" + std::to_string(i) + "]" + " " + plants[i];
        choice_seed->add(p.c_str());
    }
    choice_seed->value(0);

    choice_music->add("Grasswalk");
    choice_music->add("Moongrains");
    choice_music->add("Watery Graves");
    choice_music->add("Rigor Mormist");
    choice_music->add("Graze the Roof");
    choice_music->add("Choose Your Seeds");
    choice_music->add("Crazy Dave");
    choice_music->add("Zen Garden");
    choice_music->add("Cerebrawl");
    choice_music->add("Loonboon");
    choice_music->add("Ultimate Battle");
    choice_music->add("Brainiac Maniac");
    choice_music->value(4);

    // 2+2*1009 = 2020
    input_level->value(1009);

    choice_row->add("All Rows");
    choice_row->add("1st Row");
    choice_row->add("2nd Row");
    choice_row->add("3rd Row");
    choice_row->add("4th Row");
    choice_row->add("5th Row");
    choice_row->add("6th Row");
    choice_row->value(1);

    choice_col->add("All Columns");
    choice_col->add("1st Column");
    choice_col->add("2nd Column");
    choice_col->add("3rd Column");
    choice_col->add("4th Column");
    choice_col->add("5th Column");
    choice_col->add("6th Column");
    choice_col->add("7th Column");
    choice_col->add("8th Column");
    choice_col->add("9th Column");
    choice_col->value(1);

    for (size_t i = 0; i < 48; i++)
    {
        std::string p = "[" + std::to_string(i) + "]" + " " + plants[i];
        choice_plant->add(p.c_str());
    }
    choice_plant->value(0);

    for (size_t i = 0; i < 33; i++)
    {
        std::string z = "[" + std::to_string(i) + "]" + " " + zombies[i];
        choice_zombie->add(z.c_str());
    }
    choice_zombie->value(0);

    choice_item->add("Plants");
    choice_item->add("Zombies");
    choice_item->add("Lawn Mowers");
    choice_item->add("Graves");
    choice_item->add("Ladders");
    choice_item->add("Rakes");
    choice_item->value(2);

    for (size_t i = 0; i < 20; i++)
        check_zombie[i]->label(zombies_s[spawn_type[i]]);

    // 默认限制出怪种类数
    check_limit_count->value(1);

    for (size_t i = 0; i < 73; i++)
    {
        if (i == 0) // 冒险 5x10 关
        {
            for (size_t j = 1; j <= 5; j++)
            {
                for (size_t k = 1; k <= 10; k++)
                {
                    std::string adventure_level = std::string() + "[0]" + " " + std::string(modes[0]) //
                                                  + " " + std::to_string(j) + "-" + std::to_string(k);
                    choice_mode->add(adventure_level.c_str());
                }
            }
        }
        else
        {
            std::string mode = std::string() + "[" + std::to_string(i) + "]" + " " + std::string(modes[i]);
            choice_mode->add(mode.c_str());
        }
    }
    // 默认无尽模式
    choice_mode->value(50 + 13 - 1);

    choice_debug->add("Off");
    choice_debug->add("Spawning");
    choice_debug->add("Music");
    choice_debug->add("Memory");
    choice_debug->add("Collision");
    choice_debug->value(0);

    // 默认打开后台运行和显示隐藏游戏
    check_background->value(1);
    check_show_hidden_games->value(1);

    // 默认显示出怪选项卡
    tabs->value(group_spawn);

    // 回调函数

    button_sun->callback(cb_set_sun, this);
    button_money->callback(cb_set_money, this);
    check_auto_collect->callback(cb_auto_collect, this);

    check_no_falling->callback(cb_no_falling, this);
    check_fertilizer->callback(cb_fertilizer, this);
    check_bug_spray->callback(cb_bug_spray, this);
    check_chocolate->callback(cb_chocolate, this);
    check_tree_food->callback(cb_tree_food, this);
    button_wisdom_tree->callback(cb_wisdom_tree, this);

    check_free_planting->callback(cb_free_planting, this);
    check_planting_anywhere->callback(cb_planting_anywhere, this);
    check_fast_belt->callback(cb_fast_belt, this);
    check_lock_shovel->callback(cb_lock_shovel, this);

    choice_slot->callback(cb_get_seed, this);
    button_seed->callback(cb_set_seed, this);

    button_music->callback(cb_music, this);
    button_level->callback(cb_level, this);

    button_put_plant->callback(cb_put_plant, this);
    button_put_zombie->callback(cb_put_zombie, this);
    button_put_grave->callback(cb_put_grave, this);

    button_direct_win->callback(cb_direct_win, this);
    button_clear->callback(cb_clear, this);
    button_put_ladder->callback(cb_put_ladder, this);
    button_auto_ladder->callback(cb_auto_ladder, this);

    check_plant_invincible->callback(cb_plant_invincible, this);
    check_plant_weak->callback(cb_plant_weak, this);
    check_zombie_invincible->callback(cb_zombie_invincible, this);
    check_zombie_weak->callback(cb_zombie_weak, this);
    check_reload_instantly->callback(cb_reload_instantly, this);
    check_mushroom_awake->callback(cb_mushroom_awake, this);
    check_stop_spawning->callback(cb_stop_spawning, this);
    check_stop_zombies->callback(cb_stop_zombies, this);
    check_lock_butter->callback(cb_lock_butter, this);
    check_no_crater->callback(cb_no_crater, this);
    check_no_ice_trail->callback(cb_no_ice_trail, this);
    check_zombie_not_explode->callback(cb_zombie_not_explode, this);

    check_zombie[0]->callback(cb_spawn_mutex_0, this);
    check_zombie[3]->callback(cb_spawn_mutex_3, this);
    for (size_t i = 0; i < 20; i++)
    {
        int t = spawn_type[i];
        if ((i != 0) && (i != 3) && (t != 19) && (t != 20))
            check_zombie[i]->callback(cb_spawn_count_check, this);
    }
    button_show_details->callback(cb_show_details, this);
    button_update_details->callback(cb_update_details, this);
    check_limit_count->callback(cb_spawn_count_check, this);
    button_internal_spawn->callback(cb_internal_spawn, this);
    button_customize_spawn->callback(cb_customize_spawn, this);

    button_mix->callback(cb_mix_mode, this);
    button_userdata->callback(cb_userdata, this);

    check_no_fog->callback(cb_no_fog, this);
    check_see_vase->callback(cb_see_vase, this);
    check_background->callback(cb_background, this);
    check_readonly->callback(cb_readonly, this);

    button_file->callback(cb_open_file, this);
    button_dir->callback(cb_open_dir, this);
    button_unpack->callback(cb_unpack, this);
    button_pack->callback(cb_pack, this);

    button_debug->callback(cb_debug_mode, this);
    check_show_hidden_games->callback(cb_show_hidden_games, this);

    button_download->callback(cb_download, this);
    button_update->callback(cb_update, this);
    button_about->callback(cb_about, this);

    window_spawn->callback(cb_on_hide_details, this);

    // 根据系统换字体

    static Fl_Font pt_font = (FL_FREE_FONT + 1);
    std::string v = get_nt_version();
    if (v == "5.0" || v == "5.1")
        Fl::set_font(pt_font, "SimSun");
    else if (v == "6.0" || v == "6.1")
        Fl::set_font(pt_font, "Microsoft YaHei");
    else
        Fl::set_font(pt_font, "Microsoft YaHei UI");

    for (int i = 0; i < this->children(); i++)
        this->child(i)->labelfont(pt_font);
    {
        for (int i = 0; i < tabs->children(); i++)
        {
            tabs->child(i)->labelfont(pt_font);
            tabs->child(i)->labelsize(tabs->child(i)->labelsize() + 1);
        }
        {
            for (int i = 0; i < group_resource->children(); i++)
                group_resource->child(i)->labelfont(pt_font);
            input_sun->textfont(pt_font);
            input_money->textfont(pt_font);
            input_wisdom_tree->textfont(pt_font);
            choice_slot->textfont(pt_font);
            choice_seed->textfont(pt_font);
            choice_music->textfont(pt_font);
            input_level->textfont(pt_font);
        }
        {
            for (int i = 0; i < group_battle->children(); i++)
                group_battle->child(i)->labelfont(pt_font);
            choice_row->textfont(pt_font);
            choice_col->textfont(pt_font);
            choice_plant->textfont(pt_font);
            choice_zombie->textfont(pt_font);
            choice_item->textfont(pt_font);
        }
        {
            for (int i = 0; i < group_spawn->children(); i++)
                group_spawn->child(i)->labelfont(pt_font);
        }
        {
            for (int i = 0; i < group_others->children(); i++)
                group_others->child(i)->labelfont(pt_font);
            choice_mode->textfont(pt_font);
            input_file->textfont(pt_font);
            input_dir->textfont(pt_font);
            choice_debug->textfont(pt_font);
        }
    }
    table_spawn->labelfont(pt_font);
    button_update_details->labelfont(pt_font);
    button_update_details->labelsize(12);

    // TODO 判断语言增加提示

    // 工作类

    pvz = new PvZ();
    pvz->callback(cb_find_result, this);
    pvz->FindPvZ();

    pak = new PAK();

    // this->show(); // 在 main() 里带参调用
}

Window::~Window()
{
}

std::string Window::get_nt_version()
{
    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;
    dwVersion = GetVersion(); // 不加 manifest 的情况下 win8.1 及以上系统只返回 win8
    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));
    printf("Windows version: %d.%d (%d).\n", dwMajorVersion, dwMinorVersion, dwBuild);

    std::string ver = std::to_string(dwMajorVersion) + "." + std::to_string(dwMinorVersion);
    return ver;
}

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
    switch (result)
    {
    case PVZ_1_0_0_1051_EN:
        game_status->label("1.0.0.1051 Original (en)");
        break;
    case PVZ_1_2_0_1065_EN:
        game_status->label("1.2.0.1065 Original (en)");
        break;
    case PVZ_1_2_0_1073_EN:
        game_status->label("1.2.0.1073 GOTY (en)");
        break;
    case PVZ_1_2_0_1096_EN:
        game_status->label("1.2.0.1096 GOTY Steam (en)");
        break;
    case PVZ_1_2_0_1093_DE_ES_FR_IT:
        game_status->label("1.2.0.1093 GOTY (de/es/fr/it)");
        break;
    case PVZ_1_1_0_1056_ZH:
        game_status->label("1.1.0.1056 GOTY (zh)");
        {
            int ret = MessageBoxW(GetActiveWindow(),                                                                           //
                                  L"There are many problems with this version of game, it could crash at any time. "           //
                                  L"It is recommended to use another normal version instead, do you want to download it now?", //
                                  L"Warning",                                                                                  //
                                  MB_OKCANCEL | MB_ICONWARNING);
            if (ret == IDOK)
                ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/pvz/", //
                              nullptr, nullptr, SW_SHOWNORMAL);
        }
        break;
    case PVZ_1_1_0_1056_JA:
        game_status->label("1.1.0.1056 GOTY (ja)");
        break;
    case PVZ_1_1_0_1056_ZH_2012_06:
        game_status->label("1.1.0.1056 GOTY 2012.06 (zh)");
        break;
    case PVZ_1_1_0_1056_ZH_2012_07:
        game_status->label("1.1.0.1056 GOTY 2012.07 (zh)");
        break;
    case PVZ_UNSUPPORTED:
        game_status->label("Unsupported game version.");
        break;
    case PVZ_OPEN_ERROR:
        game_status->label("Error opening game process.");
        break;
    case PVZ_NOT_FOUND:
    default:
        game_status->label("Game window not found.");
        break;
    }
    game_status->redraw();

    if (result != PVZ_NOT_FOUND     //
        && result != PVZ_OPEN_ERROR //
        && result != PVZ_UNSUPPORTED)
    {
        this->keep_selected_feature(); // 重新找到游戏时应用所有已选功能
        // game_status_tooltip->label("?");
        // game_status_tooltip->tooltip("由于这个游戏修改技术的普遍存在， \n"
        //                              "无法完全收录识别所有改版的名称， \n"
        //                              "只能判断出其采用的原始底包版本。");
    }
    else
    {
        // game_status_tooltip->label("");
        // game_status_tooltip->tooltip(nullptr);
    }
}

void Window::keep_selected_feature()
{
    std::vector<Fl_Check_Button *> check_buttons = {
        check_auto_collect,
        check_no_falling,
        check_fertilizer,
        check_bug_spray,
        check_chocolate,
        check_tree_food,
        check_free_planting,
        check_planting_anywhere,
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
        check_show_hidden_games,
    };

    for (size_t i = 0; i < check_buttons.size(); i++)
    {
        if (check_buttons[i]->value() == 1)
        {
            check_buttons[i]->do_callback();
        }
    }
}

void Window::cb_set_sun(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_set_sun();
}

void Window::cb_set_sun()
{
    pvz->SetSun(static_cast<int>(input_sun->value()));
}

void Window::cb_set_money(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_set_money();
}

void Window::cb_set_money()
{
    pvz->SetMoney(static_cast<int>(input_money->value()));
}

void Window::cb_auto_collect(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_auto_collect();
}

void Window::cb_auto_collect()
{
    pvz->AutoCollect(check_auto_collect->value());
}

void Window::cb_no_falling(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_no_falling();
}

void Window::cb_no_falling()
{
    pvz->ZombieNoFalling(check_no_falling->value());
}

void Window::cb_fertilizer(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_fertilizer();
}

void Window::cb_fertilizer()
{
    pvz->FertilizerUnlimited(check_fertilizer->value());
}

void Window::cb_bug_spray(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_bug_spray();
}

void Window::cb_bug_spray()
{
    pvz->BugSprayUnlimited(check_bug_spray->value());
}

void Window::cb_chocolate(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_chocolate();
}

void Window::cb_chocolate()
{
    pvz->ChocolateUnlimited(check_chocolate->value());
}

void Window::cb_tree_food(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_tree_food();
}

void Window::cb_tree_food()
{
    pvz->TreeFoodUnlimited(check_tree_food->value());
}

void Window::cb_wisdom_tree(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_wisdom_tree();
}

void Window::cb_wisdom_tree()
{
    pvz->SetTreeHeight(static_cast<int>(input_wisdom_tree->value()));
}

void Window::cb_free_planting(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_free_planting();
}

void Window::cb_free_planting()
{
    pvz->FreePlanting(check_free_planting->value());
}

void Window::cb_planting_anywhere(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_planting_anywhere();
}

void Window::cb_planting_anywhere()
{
    pvz->PlantingAnywhere(check_planting_anywhere->value());
}

void Window::cb_fast_belt(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_fast_belt();
}

void Window::cb_fast_belt()
{
    pvz->FastBelt(check_fast_belt->value());
}

void Window::cb_lock_shovel(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_lock_shovel();
}

void Window::cb_lock_shovel()
{
    pvz->LockShovel(check_lock_shovel->value());
}

void Window::cb_get_seed(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_get_seed();
}

void Window::cb_get_seed()
{
    int seed_type;
    bool is_imitater;

    int seed = pvz->GetSlotSeed(choice_slot->value());
    if (seed >= 48)
    {
        seed_type = seed - 48;
        is_imitater = true;
    }
    else
    {
        seed_type = seed;
        is_imitater = false;
    }

    choice_seed->value(seed_type);
    check_seed_imitater->value(is_imitater);
}

void Window::cb_set_seed(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_set_seed();
}

void Window::cb_set_seed()
{
    int index = choice_slot->value();
    int seed_type = choice_seed->value();
    bool is_imitater = check_seed_imitater->value();

    pvz->SetSlotSeed(index, seed_type, is_imitater);
}

void Window::cb_music(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_music();
}

void Window::cb_music()
{
    pvz->SetMusic(choice_music->value() + 1);
}

void Window::cb_level(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_level();
}

void Window::cb_level()
{
    pvz->JumpLevel(static_cast<int>(input_level->value()));
}

void Window::cb_put_plant(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_plant();
}

void Window::cb_put_plant()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    int type = choice_plant->value();
    bool imitater = check_imitater->value();
    pvz->PutPlant(row, col, type, imitater);
}

void Window::cb_put_zombie(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_zombie();
}

void Window::cb_put_zombie()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    int type = choice_zombie->value();
    pvz->PutZombie(row, col, type);
}

void Window::cb_put_grave(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_grave();
}

void Window::cb_put_grave()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    pvz->PutGrave(row, col);
}

void Window::cb_direct_win(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_direct_win();
}

void Window::cb_direct_win()
{
    pvz->DirectWin(true);
}

void Window::cb_clear(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_clear();
}

void Window::cb_clear()
{
    switch (choice_item->value())
    {
    case 0: // 植物
        pvz->ClearAllPlants();
        break;
    case 1: // 僵尸
        pvz->KillAllZombies();
        break;
    case 2: // 推车
        pvz->ClearAllLawnMowers();
        break;
    case 3: // 墓碑
        pvz->ClearGridItems(1);
        break;
    case 4: // 梯子
        pvz->ClearGridItems(3);
        break;
    case 5: // 钉耙
        pvz->ClearGridItems(11);
        break;
    default:
        break;
    }
}

void Window::cb_put_ladder(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_ladder();
}

void Window::cb_put_ladder()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    pvz->PutLadder(row, col);
}

void Window::cb_auto_ladder(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_auto_ladder();
}

void Window::cb_auto_ladder()
{
    pvz->AutoLadder(true);
}

void Window::cb_plant_invincible(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_plant_invincible();
}

void Window::cb_plant_invincible()
{
    if (check_plant_weak->value())
        check_plant_weak->value(0);

    pvz->PlantWeak(false);
    pvz->PlantInvincible(check_plant_invincible->value());
}

void Window::cb_plant_weak(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_plant_weak();
}

void Window::cb_plant_weak()
{
    if (check_plant_invincible->value())
        check_plant_invincible->value(0);

    pvz->PlantInvincible(false);
    pvz->PlantWeak(check_plant_weak->value());
}

void Window::cb_zombie_invincible(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_zombie_invincible();
}

void Window::cb_zombie_invincible()
{
    if (check_zombie_weak->value())
        check_zombie_weak->value(0);

    pvz->ZombieWeak(false);
    pvz->ZombieInvincible(check_zombie_invincible->value());
}

void Window::cb_zombie_weak(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_zombie_weak();
}

void Window::cb_zombie_weak()
{
    if (check_zombie_invincible->value())
        check_zombie_invincible->value(0);

    pvz->ZombieInvincible(false);
    pvz->ZombieWeak(check_zombie_weak->value());
}

void Window::cb_reload_instantly(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_reload_instantly();
}

void Window::cb_reload_instantly()
{
    pvz->ReloadInstantly(check_reload_instantly->value());
}

void Window::cb_mushroom_awake(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_mushroom_awake();
}

void Window::cb_mushroom_awake()
{
    pvz->MushroomsAwake(check_mushroom_awake->value());
}

void Window::cb_stop_spawning(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_stop_spawning();
}

void Window::cb_stop_spawning()
{
    pvz->StopSpawning(check_stop_spawning->value());
}

void Window::cb_stop_zombies(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_stop_zombies();
}

void Window::cb_stop_zombies()
{
    pvz->StopZombies(check_stop_zombies->value());
}

void Window::cb_lock_butter(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_lock_butter();
}

void Window::cb_lock_butter()
{
    pvz->LockButter(check_lock_butter->value());
}

void Window::cb_no_crater(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_no_crater();
}

void Window::cb_no_crater()
{
    pvz->NoCrater(check_no_crater->value());
}

void Window::cb_no_ice_trail(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_no_ice_trail();
}

void Window::cb_no_ice_trail()
{
    pvz->NoIceTrail(check_no_ice_trail->value());
}

void Window::cb_zombie_not_explode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_zombie_not_explode();
}

void Window::cb_zombie_not_explode()
{
    pvz->ZombieNotExplode(check_zombie_not_explode->value());
}

void Window::cb_spawn_mutex_0(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_spawn_mutex_0();
}

void Window::cb_spawn_mutex_0()
{
    if (check_zombie[0]->value() == 1 && check_limit_count->value() == 1)
        check_zombie[3]->value(0);
    cb_spawn_count_check();
}

void Window::cb_spawn_mutex_3(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_spawn_mutex_3();
}

void Window::cb_spawn_mutex_3()
{
    if (check_zombie[3]->value() == 1 && check_limit_count->value() == 1)
        check_zombie[0]->value(0);
    cb_spawn_count_check();
}

void Window::cb_show_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_show_details();
}

void Window::cb_show_details()
{
    if (window_spawn->shown() == 0)
    {
        button_show_details->copy_label("Hide Details");
        window_spawn->show();
        cb_update_details();
    }
    else
    {
        button_show_details->copy_label("Show Details");
        window_spawn->hide();
    }
}

void Window::cb_update_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_update_details();
}

void Window::cb_update_details()
{
    std::array<int, 1000> zombies_list = pvz->GetSpawnList();
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
    window_spawn->size(860 + 120, 640 - deleted_rows * 18);
    window_spawn->redraw();
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
            if (check_limit_count->value() == 1 && count >= 11)
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

void Window::cb_internal_spawn(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_internal_spawn();
}

void Window::cb_internal_spawn()
{
    std::array<bool, 33> zombies = {false};
    for (size_t i = 0; i < 20; i++)
        zombies[spawn_type[i]] = (check_zombie[i]->value() == 1);
    zombies[0] = true;
    pvz->InternalSpawn(zombies);

    if (window_spawn->shown() == 1)
        cb_update_details();
}

void Window::cb_customize_spawn(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_customize_spawn();
}

void Window::cb_customize_spawn()
{
    std::array<bool, 33> zombies = {false};
    for (size_t i = 0; i < 20; i++)
        zombies[spawn_type[i]] = (check_zombie[i]->value() == 1);
    zombies[0] = true;
    zombies[1] = true;
    pvz->CustomizeSpawn(zombies);

    if (window_spawn->shown() == 1)
        cb_update_details();
}
void Window::cb_mix_mode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_mix_mode();
}

void Window::cb_mix_mode()
{
    int mode;
    int level;

    int m = choice_mode->value();
#ifdef _DEBUG
    std::wcout << L"选择的模式: " << m << std::endl;
#endif
    if (m < 50) // 0~49 冒险
    {
        mode = 0;
        level = m + 1; // 1 -> 1-1
    }
    else
    {
        mode = m - 50 + 1; // 1
        level = 1;
    }

    pvz->MixMode(mode, level);
}

void Window::cb_userdata(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_userdata();
}

void Window::cb_userdata()
{
    std::vector<std::wstring> paths; // 所有可能的路径

    std::string v = get_nt_version();
    // 2000/XP 系统下才会使用 `安装目录/userdata` 做存档位置
    // 需要找到游戏才能定位到游戏安装目录
    if ((v == "5.0" || v == "5.1") && !pvz->path.empty())
    {
        std::wstring exe_path = pvz->path;
        std::wstring path = exe_path.substr(0, exe_path.find_last_of(L"\\") + 1) + L"userdata";
        paths.push_back(path);
    }

    // 最常见
    paths.push_back(std::wstring(L"C:\\ProgramData\\PopCap Games\\PlantsVsZombies\\userdata"));

    // Steam 版本未打开云存档时会使用该目录
    paths.push_back(std::wstring(L"C:\\ProgramData\\Steam\\PlantsVsZombies\\userdata"));

    // 检查有没有安装 Steam
    std::wstring path = L"C:\\Program Files (x86)\\Steam\\userdata";
    HKEY hKey;
    DWORD ret = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\WOW6432Node\\Valve\\Steam", //
                              0, KEY_QUERY_VALUE, &hKey);
    if (ret == ERROR_SUCCESS)
    {
        DWORD dwType = REG_SZ;
        TCHAR szSteamPath[MAX_PATH];
        DWORD dwSize;
        DWORD ret = RegQueryValueExW(hKey, L"InstallPath", 0, &dwType, (LPBYTE)&szSteamPath, &dwSize);
        if (ret == ERROR_SUCCESS)
            path = std::wstring(szSteamPath) + L"\\userdata"; // 通过注册表找到的安装位置 + userdata
        RegCloseKey(hKey);
    }
    DWORD fa = GetFileAttributesW(path.c_str());
    if (!path.empty() && (fa != INVALID_FILE_ATTRIBUTES) && (fa & FILE_ATTRIBUTE_DIRECTORY))
    {
        WIN32_FIND_DATA ffd;
        HANDLE hf;
        hf = FindFirstFileW((path + L"\\*").c_str(), &ffd);
        if (hf != INVALID_HANDLE_VALUE)
        {
            do
            {
                std::wstring name = ffd.cFileName;
                if (name == L"." || name == L".." || name == L"thumbs.db" || name == L"Thumbs.db")
                    continue;
                if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    path = path + L"\\" + name + L"\\3590\\remote";
                    paths.push_back(path);
                }
            } while (FindNextFileW(hf, &ffd) != 0);
            FindClose(hf);
        }
    }

#ifdef _DEBUG
    std::wcout << std::endl
               << L"可能的存档文件夹: " << std::endl;
    for (size_t i = 0; i < paths.size(); i++)
        std::wcout << paths[i] << std::endl;
    std::wcout << std::endl;
#endif

    for (size_t i = 0; i < paths.size(); i++)
    {
        DWORD fa = GetFileAttributesW(paths[i].c_str());
        if ((fa != INVALID_FILE_ATTRIBUTES) && (fa & FILE_ATTRIBUTE_DIRECTORY))
        {
#ifdef _DEBUG
            std::wcout << L"文件夹存在, 正在打开: " << paths[i] << std::endl;
#endif
            ShellExecuteW(nullptr, L"open", paths[i].c_str(), nullptr, nullptr, SW_SHOWNORMAL);
        }
    }
}

void Window::cb_no_fog(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_no_fog();
}

void Window::cb_no_fog()
{
    pvz->NoFog(check_no_fog->value());
}

void Window::cb_see_vase(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_see_vase();
}

void Window::cb_see_vase()
{
    pvz->SeeVase(check_see_vase->value());
}

void Window::cb_background(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_background();
}

void Window::cb_background()
{
    pvz->BackgroundRunning(check_background->value());
}

void Window::cb_readonly(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_readonly();
}

void Window::cb_readonly()
{
    pvz->UserdataReadonly(check_readonly->value());
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
    ofn.lpstrFilter = L"PAK(*.pak)\0*.pak\0";
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
    bi.lpszTitle = L"Select the folder to be packing.";
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

void Window::cb_unpack(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_unpack();
}

void Window::cb_unpack()
{
    HANDLE hThread = CreateThread(nullptr, 0, this->cb_unpack_thread, this, 0, nullptr);
    CloseHandle(hThread);
}

DWORD Window::cb_unpack_thread(void *w)
{
    ((Window *)w)->cb_unpack_thread();
    return 0;
}

void Window::cb_unpack_thread()
{
    std::wstring src_file = utf8_decode(std::string(input_file->value()));
    std::wstring dst_dir = utf8_decode(std::string(input_dir->value()));
    if (src_file.empty() || dst_dir.empty())
        return;

    Fl::lock();
    button_file->deactivate();
    input_file->deactivate();
    button_unpack->deactivate();
    button_dir->deactivate();
    input_dir->deactivate();
    button_pack->deactivate();
    Fl::unlock();
    Fl::awake();

    int ret = pak->Unpack(src_file, dst_dir);
#ifdef _DEBUG
    std::wcout << L"解包返回值 " << ret << std::endl;
#endif
    if (ret == UNPACK_SUCCESS)
    {
        std::wstring text = L"Unpacking success, folder at: \n" + dst_dir;
        MessageBoxW(GetActiveWindow(), text.c_str(), L"Status", MB_OK | MB_ICONINFORMATION);
    }
    else
    {
        std::wstring text = L"Unpacking error.";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"Status", MB_OK | MB_ICONERROR);
    }

    Fl::lock();
    button_file->activate();
    input_file->activate();
    button_unpack->activate();
    button_dir->activate();
    input_dir->activate();
    button_pack->activate();
    Fl::unlock();
    Fl::awake();
}

void Window::cb_pack(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_pack();
}

void Window::cb_pack()
{
    HANDLE hThread = CreateThread(nullptr, 0, this->cb_pack_thread, this, 0, nullptr);
    CloseHandle(hThread);
}

DWORD Window::cb_pack_thread(void *w)
{
    ((Window *)w)->cb_pack_thread();
    return 0;
}

void Window::cb_pack_thread()
{
    std::wstring src_dir = utf8_decode(std::string(input_dir->value()));
    if (src_dir.empty())
        return;
    std::wstring dst_file = src_dir.substr(0, src_dir.find_last_of(L"\\")) + L"\\" //
                            + L"main_" + std::to_wstring(std::time(nullptr)) + L".pak";

    Fl::lock();
    button_file->deactivate();
    input_file->deactivate();
    button_unpack->deactivate();
    button_dir->deactivate();
    input_dir->deactivate();
    button_pack->deactivate();
    Fl::unlock();
    Fl::awake();

    int ret = pak->Pack(src_dir, dst_file);
#ifdef _DEBUG
    std::wcout << L"打包返回值 " << ret << std::endl;
#endif
    if (ret == PACK_SUCCESS)
    {
        std::wstring text = L"Packing success, file at: \n" + dst_file + L"\n\n" //
                            + L"Rename it to \"main.pak\" and replace the original file which has the same name (backup first).";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"Status", MB_OK | MB_ICONINFORMATION);
    }
    else
    {
        std::wstring text = L"Packing error.";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"Status", MB_OK | MB_ICONERROR);
    }

    Fl::lock();
    button_file->activate();
    input_file->activate();
    button_unpack->activate();
    button_dir->activate();
    input_dir->activate();
    button_pack->activate();
    Fl::unlock();
    Fl::awake();
}

void Window::cb_debug_mode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_debug_mode();
}

void Window::cb_debug_mode()
{
    pvz->DebugMode(choice_debug->value());
}

void Window::cb_show_hidden_games(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_show_hidden_games();
}

void Window::cb_show_hidden_games()
{
    pvz->UnlockLimboPage(check_show_hidden_games->value());
}

void Window::cb_download(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_download();
}

void Window::cb_download()
{
    ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/pvz/", nullptr, nullptr, SW_SHOWNORMAL);
}

void Window::cb_update(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_update();
}

void Window::cb_update()
{
    ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/toolkit/", nullptr, nullptr, SW_SHOWNORMAL);
}

void Window::cb_about(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_about();
}

void Window::cb_about()
{
    std::wstring text = std::wstring()                                                                 //
                        + L"PvZ Toolkit is a trainer designed for PC versions of Plants vs. Zombies\n" //
                        + L"\n"                                                                        //
                        + L"Supported game versions: \n"                                               //
                        + L"✓ 1.0.0.1051 (en)\n"                                                       //
                        + L"✓ 1.2.0.1065 (en)\n"                                                       //
                        + L"✓ 1.2.0.1073 GOTY (en)\n"                                                  //
                        + L"✓ 1.2.0.1096 GOTY Steam (en)\n"                                            //
                        + L"✓ 1.2.0.1093 GOTY Origin (de, es, fr, it)\n"                               //
                        + L"✓ 1.1.0.1056 GOTY (zh)\n"                                                  //
                        + L"✓ 1.1.0.1056 GOTY (ja)\n"                                                  //
                        + L"✓ 1.1.0.1056 GOTY 2012.06 (zh)\n"                                          //
                        + L"✓ 1.1.0.1056 GOTY 2012.07 (zh)\n"                                          //
                        + L"\n"                                                                        //
                        + L"Version: 1.1.0\n"                                                          //
                        + L"Build Date: 2020/04/16\n"                                                  //
                        + L"Toolchain: MSVC 2017 / FLTK 1.3.5\n"                                       //
                        + L"Copyright: © 2020 lmintlcx\n"                                              //
                        + L"Credit: a418569882 kmtohoem\n";
    MessageBoxW(GetActiveWindow(), text.c_str(), L"About PvZ Toolkit", MB_OK);
}

void Window::cb_on_hide_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_on_hide_details();
}

void Window::cb_on_hide_details()
{
    button_show_details->copy_label("Show Details");
    window_spawn->hide();
}

} // namespace Pt
