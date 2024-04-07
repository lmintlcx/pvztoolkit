
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
        "Giga-Gargantuar",
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

const char *zombies_zh[] =
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
        "Giga-Gargantuar",
};

const char *modes_zh[] =
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
            if (Fl::event_dy() == -1) // scroll up
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
	// Width: 75 + 35 * 20 + (35 + 25) + 2 = 837
    // Height: (18 + 3) + 18 * 33 + 2 = 617

    rows(ROWS);
    row_header(1);
    row_header_width(175);
    row_height_all(18);
    row_resize(0);

    cols(COLS);
    col_header(1);
    col_header_height(18 + 3);
    col_width_all(35);
    col_width(20 + 1 - 1, 35 + 25);
    col_resize(0);

    box(FL_NO_BOX); // Rimless

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
static char s[100]; // buffer

     // There are generally no more than 20 zombies of a certain type in a single wave, and there are generally no more than 300 zombies of a certain type in a single round.
     Fl_Color c_n = 0xffffff00u - 0x01000100u * (min(data[ROW][COL], 20) * 0xffu / 30); // Background color
     Fl_Color c_t = 0xffffff00u - 0x01010100u * (min(data[ROW][COL], 300) * 0xffu / 500); // Background color (total number)
     Fl_Color c_f = 0xcccccc00u; // Flag wave border

     int Ys = 0; // Vertical offset caused by not drawing missing categories
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
		if (total == 0) // Do not draw the wave number table header when the zombie List table is empty
             break;

        if (COL == (20 + 1 - 1)) //The last List is changed to display the total number
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
        if (data[ROW][20 + 1 - 1] == 0) // Types of zombies that cannot be drawn without drawing
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
		 if (data[ROW][20 + 1 - 1] == 0) //Zombie types that cannot be drawn without drawing
             break;

         if (data[ROW][COL] == 0) // The number of certain zombies in a certain wave is 0, so don’t display it at all.
             sprintf_s(s, "");
         else
             sprintf_s(s, "%i", data[ROW][COL]);

         fl_push_clip(X, Y - Ys, W, H);
         {
             // background
             fl_color((COL == (20 + 1 - 1)) ? c_t : c_n);
             fl_rectf(X, Y - Ys, W, H);
             // data
             fl_color(FL_GRAY0);
             fl_draw(s, X, Y - Ys, W, H, FL_ALIGN_CENTER);
             // border
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
	// Parameters width height title are ignored

     //Set window title
     this->copy_label("Statistics of Monsters");

     //Set window size
     //Table Grid size 837 x 617
    int w = 5 + 940 + 5;
    int h = 5 + 617 + 7;
    this->size(w, h);

    table_spawn = new SpawnTable(5, 5, 940, 617);
    button_update_details = new Fl_Button(5, 5, 75, 18 + 3, "···");
    button_zombies_list = new Fl_Menu_Button(5, 5, 940, 617, nullptr);
    box_mask_spawn_types = new Fl_Box(5, 5 + 18 + 3, 75, 18 * 33, nullptr);
    this->end();

    button_zombies_list->add("[Refresh]");
    button_zombies_list->add("[Save]");
    button_zombies_list->add("[Load]");
    button_zombies_list->type(Fl_Menu_Button::POPUP3);
    button_zombies_list->value(0);

    extern Fl_Font ui_font;

    button_zombies_list->textfont(ui_font);

    emoji = IsWindows8OrGreater();

    button_zombies_list->replace(0, EMOJI("🔄", "[Refresh]"));
    button_zombies_list->replace(1, EMOJI("💾", "[Save]"));
    button_zombies_list->replace(2, EMOJI("🔖", "[Load]"));
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

    int w = deleted_rows == 33 ? 450 : 5 + 940 + 5;
    int h = 5 + 617 + 7 - deleted_rows * 18;
    this->size(w, h);
    this->redraw();
}

void SpawnWindow::tooltips(bool on)
{
    button_update_details->copy_tooltip(on ? "Refresh" : "Refresh");

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

    this->copy_label(on ? "Spawning Counting" : "Spawning Counting");

    this->on = on;
}

Window::Window(int width, int height, const char *title)
    : Fl_Double_Window(width, height, title)
{
    // Parameters width height title are ignored

     //Set window title
     this->copy_label("PvZ Toolkit - Plants vs. Zombies Full Version Auxiliary Tool");

     //Set window size
     int w = 205 * 4 + 10 * 2 + 5 * (4 + 1); // width 450
     int h = 25 * 6 + 10 * 2 + 10 * (6 + 1) + 30 + 5; // height 275
     this->size(w, h);

     // coordinate system
     int m = 5; // control margin
     int th = 30; // tab height
     int tb = 5; //Tab bottom border
     int iw = 205; //Control width (1/4)
     int ih = 25; // Control height (1/6)

     int x = m + m; // No. x coordinate of a control
     int y = m + th + tb + m; // No. y coordinate of a control

     // (In the case of 4 List) Return the x coordinate based on the number of Lists
     auto c = [=](int col) -> int
     {
         return x + (iw + m) * (col - 1);
     };

     // (in the case of 6 OK) return the y coordinate based on the number of OK
     auto r = [=](int row) -> int
     {
         return y + (ih + m) * (row - 1);
     };

     //main form
    {
        tabs = new Fl_Tabs(m, m, w - m * 2, h - m * 2);
        {
            group_resource = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Resources");
            {
                check_unlock_sun_limit = new Fl_Round_Button(c(1) + 8 +55, r(1), iw - 76, ih, "");
                input_sun = new Fl_Value_Input(c(1) + 45+55, r(1), iw - 20-55, ih, "");
                button_sun = new Fl_Button(c(2) + 40 - 10, r(1), iw - 45, ih, "Sun");
                box_money = new Fl_Box(c(1) + 8, r(2), iw - 76, ih, "Wallet");
                input_money = new Fl_Value_Input(c(1) + 45+55, r(2), iw - 20-55, ih, "");
                button_money = new Fl_Button(c(2) + 40 - 10, r(2), iw - 45, ih, "Coins");
                check_auto_collected = new Fl_Check_Button(c(3), r(3), iw - 15, ih, "Automatically Collected");
                check_not_drop_loot = new Fl_Check_Button(c(4), r(3), iw, ih, "Do Not Drop Loot");
                check_fertilizer = new Fl_Check_Button(c(3), r(1), iw - 15, ih, "Unlimted Fertilizer");
                check_bug_spray = new Fl_Check_Button(c(4), r(1), iw, ih, "Unlimited Bug Spray");
                check_tree_food = new Fl_Check_Button(c(3), r(2), iw - 15, ih, "Unlimited Tree Food");
                check_chocolate = new Fl_Check_Button(c(4), r(2), iw, ih, "Unlimited Chocolate");
                box_wisdom_tree = new Fl_Box(c(1) + 8, r(3), iw - 76, ih, "Tree");
                input_wisdom_tree = new Fl_Value_Input(c(1) + 45+55, r(3), iw - 20-55, ih, "");
                button_wisdom_tree = new Fl_Button(c(2) + 40 - 10, r(3), iw - 45, ih, "Tree Feet");
                check_free_planting = new Fl_Check_Button(c(1), r(4), iw - 15, ih, "Free Planting");
                check_placed_anywhere = new Fl_Check_Button(c(2) + 30, r(4), iw - 15, ih, "Place Plants Anywhere");
                check_fast_belt = new Fl_Check_Button(c(3), r(4), iw - 15, ih, "Seamless Conveyor Belt");
                check_lock_shovel = new Fl_Check_Button(c(4), r(4), iw - 15, ih, "Shovel Continuosly");
                choice_mode = new Fl_Choice_(c(1), r(5), iw + m + iw - 15 + 5, ih, "");
				choice_adventure = new Fl_Choice_(c(3) + 20 - 20, r(5), iw - 20 + 15 - 20, ih, "");
                button_mix = new Fl_Button(c(4) - 15 + 15, r(5), iw - 15 - 20, ih, "Modify Mode");
                input_level = new Fl_Value_Input(c(3) + 20 - 20, r(6), iw - 20 + 15 - 20, ih, "");
                button_level = new Fl_Button(c(4) + 15 - 15, r(6), iw - 15 - 20, ih, "Endless Rounds");
                button_unlock = new Fl_Button(c(1), r(6), iw - 15 + 40, ih * 2, "Get Gold SunFlower Trophy");
                button_direct_win = new Fl_Button(c(2) + 20 + 15, r(6), iw - 45, ih, "Level Complete");
            }
            group_resource->end();

            group_battle = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Battlefield");
            {
                choice_row = new Fl_Choice_(c(1), r(1), iw - 10, ih, "");
                choice_col = new Fl_Choice_(c(1), r(2), iw - 10, ih, "");
                choice_plant = new Fl_Choice_(c(2) - 10, r(1), iw + 10 + 40, ih, "");
                choice_zombie = new Fl_Choice_(c(2) - 10, r(2), iw + 10 + 40, ih, "");
                button_put_plant = new Fl_Button(c(3) + 40, r(1), iw - 40 + 20, ih, "Plant");
                check_imitater = new Fl_Check_Button(c(4) + 20, r(1), iw - 20, ih, "Imitator");
                button_put_zombie = new Fl_Button(c(3) + 40, r(2), iw - 40 + 20, ih, "Zombie");
                button_put_ladder = new Fl_Button(c(4) + 20, r(2), iw - 20, ih, "Ladder");
                button_put_grave = new Fl_Button(c(4) + 20, r(1), iw - 20, ih, "Grave");
                button_put_rake = new Fl_Button(c(4) + 20, r(3), iw - 20, ih, "Rake");
                button_lawn_mower = new Fl_Menu_Button(c(1), r(3), iw - 10, ih, "Lawn Mowers");
                choice_item = new Fl_Choice_(c(2) - 10, r(3), iw + 10 - 130, ih, "");
                button_clear = new Fl_Button(c(2) + iw - 126 + m, r(3), iw - 45, ih, "Clear");
                check_plant_invincible = new Fl_Check_Button(c(1), r(4), iw - 15, ih, "Plant Invincible");
                check_plant_weak = new Fl_Check_Button(c(2), r(4), iw - 15, ih, "Plant Weak");
                check_zombie_invincible = new Fl_Check_Button(c(3), r(4), iw - 15, ih, "Zombie Invincible");
                check_zombie_weak = new Fl_Check_Button(c(4), r(4), iw - 15, ih, "Zombie Weak");
                check_reload_instantly = new Fl_Check_Button(c(1), r(5), iw - 15, ih, "Reload Instantly");
                check_mushroom_awake = new Fl_Check_Button(c(2), r(5), iw - 15, ih, "Mushroom Awake");
                check_stop_spawning = new Fl_Check_Button(c(3), r(5), iw - 15, ih, "Spawning Paused");
                check_stop_zombies = new Fl_Check_Button(c(4), r(5), iw - 15, ih, "Stay In Place");
                check_lock_butter = new Fl_Check_Button(c(1), r(6), iw - 15, ih, "Always Butter");
                check_no_crater = new Fl_Check_Button(c(2), r(6), iw - 15, ih, "No Crater");
                check_no_ice_trail = new Fl_Check_Button(c(3), r(6), iw - 15, ih, "No Ice Trail");
                check_zombie_not_explode = new Fl_Check_Button(c(4), r(6), iw - 15, ih, "Zombie Never Explode");
            }
            group_battle->end();

            group_lineup = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Setups");
            {
                choice_slot = new Fl_Choice_(c(1), r(1), iw - 10 - 2, ih, "");
                choice_seed = new Fl_Choice_(c(2) - 10 + 22 - 24, r(1), iw - 12, ih, "");
                button_seed = new Fl_Button(c(3) - 24, r(1), iw, ih, "Replace Seed");
                check_seed_imitater = new Fl_Check_Button(c(4) - 24, r(1), iw - 20, ih, "Imitator");
                check_lineup_mode = new Fl_Check_Button(c(1), r(2), iw + 12, ih, "Lineup Mode Shortcut");
                button_auto_ladder = new Fl_Button(c(2) + 12 - 24, r(2), iw - 12, ih, "Smart Ladder");
                button_put_lily_pad = new Fl_Menu_Button(c(3) - 24, r(2), iw, ih, "Lily Pad On Pool");
                button_put_flower_pot = new Fl_Menu_Button(c(4) - 24, r(2), iw, ih, "Flower Pot On Roof");
                button_reset = new Fl_Button(c(1), r(3), iw + 12 - 24, ih, "Reset Scene");
                choice_scene = new Fl_Choice_(c(2) + 12 - 24, r(3), iw - 12, ih, "");
                button_load_lineup = new Fl_Button(c(3) - 24, r(3), iw * 2 + 10, ih, "Load Formation List File (***.yml)");
                choice_lineup_name[0] = new Fl_Choice_(c(3) - 24, r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[1] = new Fl_Choice_(c(3) - 24, r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[2] = new Fl_Choice_(c(3) - 24, r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[3] = new Fl_Choice_(c(3) - 24, r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[4] = new Fl_Choice_(c(3) - 24, r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[5] = new Fl_Choice_(c(3) - 24, r(3), iw * 2 + 10, ih, "");
                buffer_lineup_string = new Fl_Text_Buffer();
                editor_lineup_string = new Fl_Text_Editor(c(1), r(4), iw * 4 + 10 * 3, ih * 2 + 10 + 2, "");
                button_get_lineup = new Fl_Button(c(1) + 100, r(6), iw - 15, ih, "Get Lineup Code");
                button_copy_lineup = new Fl_Button(c(1) + 100, r(7), iw - 15, ih, "Copy / Export");
                button_paste_lineup = new Fl_Button(c(4) - 100 + 15, r(7), iw - 15, ih, "Paste / Import");
                button_set_lineup = new Fl_Button(c(4)-100 + 15, r(6), iw - 15, ih, "Apply Current Build");
                button_capture = new Fl_Button(c(3) - 15 - 15 - 100 + 30, r(6), iw - 15, ih * 2, "Screenshot To ClipBoard");
            }
            group_lineup->end();

            group_spawn = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Spawning");
            {
                int tmp[20] = {2, 3, 4, 5, 6,       //
                               7, 8, 11, 12, 14,    //
                               15, 16, 17, 18, 19,  //
                               20, 21, 22, 23, 32}; //
                memcpy(spawn_type, tmp, sizeof(tmp));
                for (size_t row = 0; row < 4; row++)
                    for (size_t col = 0; col < 5; col++)
                        check_zombie[row * 5 + col] = new Fl_Check_Button                               //
                            (x + 8 + (iw - 42 + m) * col, y + 5 + (ih + 7 + m) * (row+1), iw - 62, ih, ""); //
                button_show_details = new Fl_Button(c(1), r(7)+10, iw, ih, "Show Details");
                choice_giga_weight = new Fl_Choice_(c(2) + 5, r(7)+10, iw - 20, ih, "");
                check_giga_limit = new Fl_Check_Button(c(3) - 55 + 40, r(7)+10, iw - 40, ih, "Variable Speed");
                button_set_spawn = new Fl_Button(c(4) - 55, r(7)+10, iw + 55 - 5, ih, "Extreme Monsters (Evenly Filled)");
                button_spawn_extra = new Fl_Menu_Button(m, m + th, w - m * 2, h - m * 2 - th - 42, nullptr);
                button_spawn_mode = new Fl_Menu_Button(c(4) - 55, r(7)+10, iw + 55 - 5, ih, "Select Spawning Mode：");
				check_reg_zombie = new Fl_Check_Button(c(1) + 10, r(1) + 5, iw - 40, ih, "Zombie");  // Added zombie button   
				check_reg_zombie->value(1); // Set value
				bool on  = check_reg_zombie->value()==1; // Defined bool
				check_reg_zombie->deactivate(); // Deactivated Button
            }
            group_spawn->end();

            group_others = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Others");
            {
                choice_music = new Fl_Choice_(c(1), r(1), iw + m + iw - 15, ih, "");
                button_music = new Fl_Button(c(3) - 15, r(1), iw, ih, "Background Music");
                button_userdata = new Fl_Button(c(4) - 15, r(1), iw + 15, ih, "Open Userdata Folder");
                check_no_fog = new Fl_Check_Button(c(1), r(2), iw - 15, ih, "Clear Fog");
                check_see_vase = new Fl_Check_Button(c(2) - 15 -5, r(2), iw - 15, ih, "Transparent Vase");
                check_background = new Fl_Check_Button(c(3) - 30 + 15, r(2), iw + 15, ih, "Enable Background Running");
                check_readonly = new Fl_Check_Button(c(4) - 15, r(2), iw + 15, ih, "Disable Delete / Save Userdata");
                button_file = new Fl_Button(c(1), r(3), iw - 20, ih, "Choose File");
                input_file = new Fl_Input_(c(2) - 20, r(3), iw + 20 + m + iw + 45, ih, "");
                button_unpack = new Fl_Button(c(4) + 45, r(3), iw - 45, ih, "Extract");
                button_dir = new Fl_Button(c(1), r(4), iw - 20, ih, "Choose Folder");
                input_dir = new Fl_Input_(c(2) - 20, r(4), iw + 20 + m + iw + 45, ih, "");
                button_pack = new Fl_Button(c(4) + 45, r(4), iw  - 45, ih, "Pack");
                choice_debug = new Fl_Choice_(c(1) - 5, r(5), iw - 30 + 15, ih, "");
                button_debug = new Fl_Button(c(2) - 20, r(5), iw - 40, ih, "Debug");
                choice_speed = new Fl_Choice_(c(3) - 70 + 10 + 30, r(5), iw - 30 - 120, ih, "");
                button_speed = new Fl_Button(c(3) - 100 + 10 + 120, r(5), iw - 40 + 25, ih, "Speed");
                check_limbo_page = new Fl_Check_Button(c(4) + 85 - 40, r(5), iw + 15, ih, "Show Limbo Page");
                choice_scheme = new Fl_Choice_(c(1) - 5, r(6), iw - 15, ih, "");
                check_tooltips = new Fl_Check_Button(c(0), r(0), iw - 40, ih, "English Tooltips");
                button_document = new Fl_Button(c(3) + 30, r(6), iw - 15, ih, "Document");
                button_about = new Fl_Button(c(4) + 15, r(6), iw - 15, ih, "About ...");
            }
            group_others->end();
        }
        tabs->end();

        box_mask_resource = new Fl_Box(10 + 1 + (40 + 2) * 0, 10, 40, 30, "");
        box_mask_battle = new Fl_Box(10 + 1 + (40 + 2) * 1, 10, 40, 30, "");
        box_mask_lineup = new Fl_Box(10 + 1 + (40 + 2) * 2, 10, 40, 30, "");
        box_mask_spawn = new Fl_Box(10 + 1 + (40 + 2) * 3, 10, 40, 30, "");
        box_mask_others = new Fl_Box(10 + 1 + (40 + 2) * 4, 10, 40, 30, "");

        game_status = new Fl_Box(460, 12, 250, 25, "");
        game_status_tip = new Fl_Box(750, 12, 15, 25, "");
    }
    this->end();

    // Defaults

    // tab color
    group_resource->selection_color(FL_DARK2);
    group_battle->selection_color(FL_DARK2);
    group_lineup->selection_color(FL_DARK2);
    group_spawn->selection_color(FL_DARK2);
    group_others->selection_color(FL_DARK2);
    tabs->selection_color(FL_WHITE);

    // Sunlight
     input_sun->bounds(0, 9990);
     input_sun->value(8000);

     // money
     input_money->bounds(0, 99999);
     input_money->value(99999);

     // wisdom Tree
     input_wisdom_tree->bounds(0, 1000);
     input_wisdom_tree->value(1437);

     for (size_t i = 0; i < 73; i++)
         choice_mode->add(("[" + std::to_string(i) + "]" + " " + modes_zh[i]).c_str());

     //Default endless mode
    choice_mode->value(13);

    for (size_t j = 1; j <= 5; j++)
        for (size_t k = 1; k <= 10; k++)
            choice_adventure->add((std::to_string(j) + " - " + std::to_string(k)).c_str());

    choice_adventure->value(39); // 4-10
    choice_adventure->deactivate();

    // 1010 * 2 + 2 = 2022
    input_level->bounds(0, 10000000);
    input_level->value(1010);

    choice_row->add("All Rows");
    choice_row->add("1st Row");
    choice_row->add("2nd Row");
    choice_row->add("3rd Row");
    choice_row->add("4th Row");
    choice_row->add("5th Row");
    choice_row->add("6th Row");

    choice_row->value(1); // No. 1 Row

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

    choice_col->value(1); // No. 1 Column

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

    button_lawn_mower->add("[Start Up");
    button_lawn_mower->add("[Delete]");
    button_lawn_mower->add("[Recover]");

    choice_item->add("Plant");
    choice_item->add("Zombie");
    choice_item->add("Ladder");
    choice_item->add("Grave");
    choice_item->add("Rake");

    choice_item->value(3); // tombstone

    choice_slot->add("1st Seed");
    choice_slot->add("2nd Seed");
    choice_slot->add("3rd Seed");
    choice_slot->add("4th Seed");
    choice_slot->add("5th Seed");
    choice_slot->add("6th Seed");
    choice_slot->add("7th Seed");
    choice_slot->add("8th Seed");
    choice_slot->add("9th Seed");
    choice_slot->add("10th Seed");

    choice_slot->value(0); // No.一Choice Slot

    for (size_t i = 0; i < 48; i++)
    {
        std::string p = "[" + std::to_string(i) + "]" + " " + plants_zh[i];
        choice_seed->add(p.c_str());
    }

    choice_seed->value(0); // No.A card

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

    choice_scene->add("[0] Day");
    choice_scene->add("[1] Night");
    choice_scene->add("[2] Pool");
    choice_scene->add("[3] Fog");
    choice_scene->add("[4] Roof");
    choice_scene->add("[5] Moon");

    choice_scene->value(2); // Pool

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
    editor_lineup_string->deactivate(); // Not editable

    //Monster name
    for (size_t i = 0; i < 20; i++)
        check_zombie[i]->copy_label(zombies_zh[spawn_type[i]]);

    // Giga-Gargantuar weight range in non-huge waves
    for (size_t w = 1000; w <= 6000; w += 100)
        choice_giga_weight->add(std::to_string(w).c_str());
    choice_giga_weight->value(0);

    // The default limit is strange
    choice_giga_weight->deactivate();
    check_giga_limit->activate();

    button_spawn_extra->add("[Clear Selected]", 0, cb_clear_checked_zombies, this);
    button_spawn_extra->add("[Remove Restrictions]", 0, cb_disable_limit_species, this);
    button_spawn_extra->type(Fl_Menu_Button::POPUP3);
    button_spawn_extra->value(0);

    button_spawn_mode->add("Natural (Game Generate)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->add("Extreme (Filling Evenly)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->add("Simulate (Weighted Random)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->type(Fl_Menu_Button::POPUP3);
    button_spawn_mode->value(1); // Extreme (Filling Evenly)

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

    choice_debug->add("Off");
    choice_debug->add("Spawning");
    choice_debug->add("Music");
    choice_debug->add("Memory");
    choice_debug->add("Collision");

    choice_debug->value(0); // Off

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

    // By default, open the background operation OK and show hidden games
    check_background->value(1);
    check_limbo_page->value(1);

    // By default, the strange tab is displayed
    tabs->value(group_spawn);

    // Callback

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
    check_tooltips->callback(cb_tooltips, this); // Overload
    button_document->callback(cb_document, this);
    button_about->callback(cb_about, this);

    // set font

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
            editor_lineup_string->textfont(ls_font); // Formation string special font
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
        button_capture->copy_label("📷 Screenshot To ClipBoard");
    }

    button_unlock->copy_label(EMOJI("🏆", "Get Golden Sunflower Trophy"));

    button_lawn_mower->replace(0, EMOJI("➡️", "[Start]"));
    button_lawn_mower->replace(1, EMOJI("🆑", "[Delete]"));
    button_lawn_mower->replace(2, EMOJI("🔄", "[Restore]"));

    button_reset->copy_label(EMOJI("⏳", "Reset Scene"));

    button_spawn_extra->replace(0, EMOJI("❌", "[Clear Selected]"));
    button_spawn_extra->replace(1, EMOJI("❎", "[Remove Restrictions]"));

    button_show_details->copy_label(EMOJI("📈", "Show Details"));

    button_music->copy_label(EMOJI("🎵", "Background Music"));
    button_userdata->copy_label(EMOJI("💾", "Open Userdata Folder"));
    button_document->copy_label(EMOJI("🌏", "Document"));

    // Default OK callback function

     // Automatically import the formation List table
     import_lineup_list(true);

     // Get the string of the formation
     choice_scene->do_callback();

     //Set control tooltips
     check_tooltips->do_callback();

     // this->show(); // Called with parameters in main()

     ReadSettings(); // Read settings

     // Center the window
     this->position((Fl::w() - this->w()) / 2, (Fl::h() - this->h()) / 2);

     //Default focus control
     button_sun->take_focus();
}

Window::~Window()
{
     WriteSettings(); // Save settings
}

void Window::ReadSettings()
{
     // Registry configuration version v1

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

        wchar_t lang[15];    // language
        DWORD scale;         // zoom
        int scheme;          // style
        wchar_t zombies[20]; // Out of strange (spawn types) (0-20 binary string)
        int mode;            // spawn mode (0-2)
        int sun;             // sunlight
        int money;           // gold
        int level;           // number of rounds (0~10000000)
        unsigned int page;   // page (0-4)

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
        // Display English prompt box in non-Chinese areas
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
                               + "The software interface has followed the system scaling:"              //
                               + std::to_string(dpi * 100 / 96) + "%%。\n\n" //
                               + "Press Esc alone to restore the default window size,\n"     //
                               + "Press the Ctrl and + / - keys simultaneously to zoom in and out of the window.";  //
            fl_message_title("Iterface Zoom");
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

        // No.Show the document once it is opened
        fl_message_title("Document");
        int c = fl_choice("This is your first time running OK PvZ Toolkit, do you want to read the online tutorial first? \n" //
                          "It can also be accessed by clicking the Document button on the Others page of the modifier interface.",      //
                          "No", "Yes", 0);
        if (c == 1)
            cb_document();
    }
}

void Window::WriteSettings()
{
    // Registry configuration version v1

    // language
    wchar_t langChinese[] = L"简体中文";
    wchar_t langEnglish[] = L"English";

    // zoom
     float scale = Fl::screen_scale(this->screen_num());

     // style
     int scheme = choice_scheme->value();

     // strange
     wchar_t zombies[20] = {0};
     for (size_t i = 0; i < 20; i++)
         zombies[i] = (this->check_zombie[i]->value() == 1 ? L'1' : L'0');

     // model
     int mode = button_spawn_mode->value();

     // Sunlight
     int sun = static_cast<int>(input_sun->value());

     // gold coins
     int money = static_cast<int>(input_money->value());

     //Number of rounds
     int level = static_cast<int>(input_level->value());

     // page
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
    // Apply all selected features when the game is found again
     if (result != PVZ_NOT_FOUND && result != PVZ_OPEN_ERROR && result != PVZ_UNSUPPORTED)
         this->keep_selected_feature();

    // Some versions only implement some functions
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
        game_status->copy_label("0.1.1.1014 English Beta");
        break;
    case PVZ_BETA_0_9_9_1029_EN:
        game_status->copy_label("0.9.9.1029 English Beta");
        break;
    case PVZ_1_0_0_1051_EN:
        game_status->copy_label("1.0.0.1051 English Origional");
        break;
    case PVZ_1_2_0_1065_EN:
        game_status->copy_label("1.2.0.1065 English Remastered Version");
        break;
    case PVZ_1_0_4_7924_ES:
        game_status->copy_label("1.0.4.7924 Spanish Version");
        break;
    case PVZ_1_0_7_3556_ES:
        game_status->copy_label("1.0.7.3556 Spanish Version");
        break;
    case PVZ_1_0_7_3467_RU:
        game_status->copy_label("1.0.7.3467 Russian Version");
        break;
    case PVZ_GOTY_1_2_0_1073_EN:
        game_status->copy_label("1.2.0.1073 English Annual Version");
        break;
    case PVZ_GOTY_1_2_0_1096_EN:
        game_status->copy_label("1.2.0.1096 English Annual Version");
        break;
    case PVZ_GOTY_1_2_0_1093_DE_ES_FR_IT:
        game_status->copy_label("1.2.0.1093 GOTY Origin (de/es/fr/it)");
        break;
    case PVZ_GOTY_1_1_0_1056_ZH:
        game_status->copy_label("1.1.0.1056 Chinese Edition");
        if (!this->bad_version_warned)
        {
            this->bad_version_warned = true;
            fl_message_title("Kind Tips");
            int c = fl_choice("This version of the game has serious issues and may crash at any time. \n" //
                              "It is recommended to use other versions that can work normally. Do you want to download it now?",  //
                              "No", "Yes", 0);
            if (c == 1)
                ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/download/", //
                              nullptr, nullptr, SW_SHOWNORMAL);
        }
        break;
    case PVZ_GOTY_1_1_0_1056_JA:
        game_status->copy_label("1.1.0.1056 Japanese Annual Edition");
        break;
    case PVZ_GOTY_1_1_0_1056_ZH_2012_06:
        game_status->copy_label("1.1.0.1056 Chinese Annual Plus");
        break;
    case PVZ_GOTY_1_1_0_1056_ZH_2012_07:
        game_status->copy_label("1.1.0.1056 Chinese Annual Plus");
        break;
    case PVZ_UNSUPPORTED:
        game_status->copy_label("Unsupported Game Version");
        break;
    case PVZ_OPEN_ERROR:
        game_status->copy_label("Error opening game process.");
        break;
    case PVZ_NOT_FOUND:
    default:
        game_status->copy_label("No game window was found.");
        break;
    }

    if (result == PVZ_NOT_FOUND)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Run Plants vs. Zombies first."
                                         : "Run Plants vs. Zombies first.");
    }
    else if (result == PVZ_OPEN_ERROR)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Try run Pt as administrator."
                                         : "Try run Pt as administrator.");
    }
    else if (result == PVZ_UNSUPPORTED)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Contact author to add support."
                                         : "Contact author to add support.");
    }
    else if (result == PVZ_BETA_0_1_1_1014_EN)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Partial support for beta version."
                                         : "Limited feature support for early beta versions,\n"
                                           "The serial number and name of the game object do not correspond exactly.");
    }
    else if (result == PVZ_BETA_0_9_9_1029_EN)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Partial support for beta version."
                                         : "Partial support for beta version.");
    }
    else if (result == PVZ_GOTY_1_1_0_1056_ZH)
    {
        game_status_tip->copy_label(emoji_i ? "🛈" : "i");
        game_status_tip->copy_tooltip(on ? "Replace this bad game version."
                                         : "Replace this bad game version.");
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
        check_lineup_mode, // Put this at the end
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
    if (choice_mode->value() == 0) // adventure mode
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
                    // std::wcout << L"Import the formation List table: " << name << std::endl;
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
            std::wcout << L"open a file: " << std::wstring(szFileName) << std::endl;
#endif
            import_lineup_list_file(szFileName);
        }
    }

    if (this->lineups.empty())
        return;

    // sort
     auto LessThan = [&](const Lineup &l1, const Lineup &l2)
     { return l1.weight < l2.weight; };
     std::sort(this->lineups.begin(), this->lineups.end(), LessThan);

     // insert
     for (size_t i = 0; i < this->lineups.size(); i++)
     {
         uint32_t scene = static_cast<uint32_t>(this->lineups[i].scene);
         std::string name = this->lineups[i].lineup_name;

         while (choice_lineup_name[scene]->find_index(name.c_str()) != -1)
             name += " "; // Fill in the blank after the same name Grid

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
        if (line == 1) // No.一OK
        {
            if (str != "#! pvztoolkit")
                break;
        }
        else
        {
            if (str[0] == '#' || str.empty()) //Comment or empty OK
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
        std::wstring title = file + L" " + L"Formation List table file Grid error";
        std::wstring text;
        for (size_t i = 0; i < err_lst.size(); i++)
        {
            if (i > 11)
            {
                text += std::wstring() + L"\n" + L"(and many more not shown...)";
                break;
            }
            auto [l, s] = err_lst[i];
            if (s.length() > 49)
                s = s.substr(0, 48) + " ...";
            text += std::wstring()                            //
                    + L"No. " + std::to_wstring(l) + L" OK： " //
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

    //Remove invisible characters
     str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
     str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
     str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
     str.erase(std::remove(str.begin(), str.end(), '\v'), str.end());
     str.erase(std::remove(str.begin(), str.end(), '\f'), str.end());
     //Remove the empty Grid at the beginning and end
     str.erase(0, str.find_first_not_of(' '));
     str.erase(str.find_last_not_of(' ') + 1);
     //Remove excess empty Grid
     str = std::regex_replace(str, std::regex("( ){2,}"), " ");
     str = std::regex_replace(str, std::regex(", "), ",");
     str = std::regex_replace(str, std::regex(" ,"), ",");

     //Convert to new Grid format
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
    int count = 1; // General stiffness will come out
    for (size_t i = 0; i < 20; i++)
        if ((spawn_type[i] != 19) && (spawn_type[i] != 20))
            count += check_zombie[i]->value() == 1 ? 1 : 0;
#ifdef _DEBUG
    std::wcout << L"The total number of monsters (including general zombies and excluding snowman bungee jumping):" << count << std::endl;
#endif

    for (size_t i = 0; i < 20; i++)
    {
        if ((spawn_type[i] != 19) && (spawn_type[i] != 20))
        {
            if (limit_species && count >= 11) // Limit the total number of monster types
             {
                 // The limit has been exceeded, deactivate the unselected ones.
                 if (check_zombie[i]->value() == 0)
                     check_zombie[i]->deactivate();
             }
             else
             {
                 // Not exceeded, enable all disabled ones
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
        button_spawn_extra->replace(1, EMOJI("✅", "Enable Restrictions"));
    }
    else
    {
        limit_species = true;
        button_spawn_extra->replace(1, EMOJI("❎", "[Remove Restrictions]"));
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
    case 0: // nature
        choice_giga_weight->deactivate();
        check_giga_limit->deactivate();
        button_set_spawn->copy_label("Natural (Game Generate)");
        button_set_spawn->copy_tooltip(on ? "Natural (Game Generate)" : nullptr);
        break;

    case 1: // limit
    default:
        choice_giga_weight->deactivate();
        check_giga_limit->activate();
        button_set_spawn->copy_label("Extreme (Filling Evenly)");
        button_set_spawn->copy_tooltip(on ? "Extreme (Filling Evenly)" : nullptr);
        break;

    case 2: // simulation
        choice_giga_weight->activate();
        check_giga_limit->activate();
        button_set_spawn->copy_label("Simulate (Weighted Random)");
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
        std::wcout << L"open a file: " << std::wstring(szFileName) << std::endl;
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
    bi.lpszTitle = L"Select Folder To Pack：";
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
            std::wcout << L"Choose Folder" << std::wstring(szPathName) << std::endl;
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

    check_unlock_sun_limit->copy_tooltip("Disable Sun Upper Limit");
    input_sun->copy_tooltip("0 ~ 9990");
    input_money->copy_tooltip("0 ~ 99999");
	choice_mode->copy_tooltip("Game Mode");
	choice_adventure->copy_tooltip("Adventure Mode Level");
    input_wisdom_tree->copy_tooltip("0 ~ 2,147,483,647");
    input_level->copy_tooltip("0 ~ 10000000");

    
    
    for (size_t i = 0; i < 6; i++)
        choice_lineup_name[i]->copy_tooltip("(Lineup Name)");
    editor_lineup_string->copy_tooltip(on ? "(Lineup Code)" : "(Lineup Code)");

    
    choice_giga_weight->copy_tooltip(on ? "Giga-Gargantuar\'s weight in non-huge waves.\nOriginal: 1000 (non-huge waves), 6000 (huge waves)."
                                        : "Giga-Gargantuar\'s weight in non-huge waves.\nOriginal: 1000 (non-huge waves), 6000 (huge waves).");
    check_giga_limit->copy_tooltip(on ? "No Giga-Gargantuar in 11th ~ 19th waves."
                                      : "No Giga-Gargantuar in 11th ~ 19th waves.");
    button_set_spawn->copy_tooltip(on ? "Right click to change spawning mode."
                                      : "Right click to change spawning mode.");

   
    input_file->copy_tooltip(on ? "(File Path)" : "(File Path)");
    input_dir->copy_tooltip(on ? "(Folder Path)" : "(Folder Path)");
    
    cb_find_result_tooltip();

    // trigger redisplay
    if (on && this->shown())
    {
        HWND me = fl_xid(this);
        POINT point = {0, 0};
        SendMessageW(me, WM_MOUSEMOVE, 0, MAKELONG(point.x, point.y));
        GetCursorPos(&point);
        ScreenToClient(me, &point);
        SendMessageW(me, WM_MOUSEMOVE, 0, MAKELONG(point.x, point.y));
    }

    // Update the title by the way

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
                   : "Plants vs. Zombies All Version Toolkit";
    else if (dpi <= 120)
        title = on ? "Plants vs. Zombies Toolkit - English Version"
                   : "Plants vs. Zombies Toolkit - English Version";
    else
        title = on ? "PvZ Toolkit"
                   : "PvZ Toolkit";
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
                      + "PvZ Toolkit" + "\n"                            //
                       + "Plants vs. Zombies All Version Toolkit" + "\n"                      //
                       + "\n"                                                     //
                       + "Website：" + "\t\t" + "https://pvz.lmintlcx.com/" + "\n" //
                       + "\n"                                                     //
                       + "Version：" + "\t\t " + version_full + "\n"                //
                       + "Date：" + "\t\t\t  " + build_date_time + "\n"             //
                       + "Copyright：" + "\t\t" + "© 2020~2022 L.Mint. LCX" + "\n"   //
                       + "\n"                                                     //
                       + "Origin：" + "                    " + "PVZ Helper 1.8.7" + "\n"          //
                       + "Dependencies：" + "\t" + "    FLTK 1.4 + zlib 1.2.12" + "\n"    //
                       + "Credits：" + "\t\t  " + "kmtohoem 63enjoy 273.15K" + "\n" //
					   + "\n"                                                   //
					   + "Modified by:" + "\t\t" + "shorty#3746" + "\n" //
   					   + "Source code:" + "\t" + "      https://github.com/shortydoggg/pvztoolkit" + "\n"; //

    fl_message_title("About PvZ Toolkit");
    fl_message(text.c_str());
}

} // namespace Pt
