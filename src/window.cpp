
#include "window.h"

#define IDI_ICON 1001

namespace Pt
{

const char *plants[] =
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

const char *zombies[] =
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
        "搞基",
        "红眼",
};

const char *modes[] =
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

SpawnTable::SpawnTable(int X, int Y, int W, int H, const char *L = 0)
    : Fl_Table(X, Y, W, H, L)
{
    rows(ROWS);
    row_header(1);
    row_header_width(75);
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
            if (zombies_list[i * 50 + j] > 32 || zombies_list[i * 50 + j] < 0)
                continue;
            data[zombies_list[i * 50 + j]][i] += 1;
            data[zombies_list[i * 50 + j]][20 + 1 - 1] += 1;
            total += 1;
        }
    }

    this->redraw();
}

void SpawnTable::draw_header(const char *s, int X, int Y, int W, int H)
{
    fl_push_clip(X, Y, W, H);
    fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
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
        draw_header(s, X, Y, W, H);
        return;
    case CONTEXT_ROW_HEADER:
        z = "[" + std::to_string(ROW) + "]" + " " + zombies[ROW];
        sprintf_s(s, "%s", z.c_str());
        draw_header(s, X, Y, W, H);
        return;
    case CONTEXT_CELL:
        sprintf_s(s, "%i", data[ROW][COL]);
        if (COL == (20 + 1 - 1))
            c = 0xffffff00 - 0x02020200 * int(atoi(s) / 10); // 2 <256/(1000/10)
        else if (COL == (10 - 1) || COL == (20 - 1))
            c = 0xf6f0f600 - 0x05000500 * atoi(s); // 5 <246/50 ??
        else
            c = 0xffffff00 - 0x05000500 * atoi(s); // 5 <256/50
        draw_data(s, X, Y, W, H, c);
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

    int w = 450; // 窗口宽度
    int h = 270; // 窗口高度
    int m = 10;  // 控件边距
    int th = 30; // 选项卡高度
    int iw = 95; // 控件宽度 (1/4)
    int ih = 25; // 控件高度 (1/6)

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
            group_resource = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "资源");
            {
                input_sun = new Fl_Value_Input(c(1) + 30, r(1), iw, ih, "");
                button_sun = new Fl_Button(c(2) + 30, r(1), iw - 40, ih, "阳光");
                input_money = new Fl_Value_Input(c(1) + 30, r(2), iw, ih, "10x");
                button_money = new Fl_Button(c(2) + 30, r(2), iw - 40, ih, "金钱");
                check_auto_collect = new Fl_Check_Button(c(1), r(3), iw - 15, ih, "自动收集");
                check_no_falling = new Fl_Check_Button(c(2), r(3), iw, ih, "僵尸不掉钱");
                check_fertilizer = new Fl_Check_Button(c(3), r(1), iw - 15, ih, "花肥无限");
                check_bug_spray = new Fl_Check_Button(c(4), r(1), iw, ih, "杀虫剂无限");
                check_chocolate = new Fl_Check_Button(c(3), r(2), iw, ih, "巧克力无限");
                check_tree_food = new Fl_Check_Button(c(4), r(2), iw - 15, ih, "树肥无限");
                input_wisdom_tree = new Fl_Value_Input(c(3) + 15, r(3), iw - 15, ih, "");
                button_wisdom_tree = new Fl_Button(c(4), r(3), iw, ih, "智慧树高度");
                check_free_planting = new Fl_Check_Button(c(1), r(4), iw - 15, ih, "免费用卡");
                check_planting_anywhere = new Fl_Check_Button(c(2), r(4), iw - 15, ih, "随意放置");
                check_fast_belt = new Fl_Check_Button(c(3), r(4), iw - 15, ih, "连续传送");
                check_lock_shovel = new Fl_Check_Button(c(4), r(4), iw - 15, ih, "锁定铲子");
                choice_slot = new Fl_Choice_(c(1), r(5), iw - 10, ih, "");
                choice_seed = new Fl_Choice_(c(2) - 10, r(5), iw + 10 + 40, ih, "");
                check_seed_imitater = new Fl_Check_Button(c(3) + 40, r(5), iw - 40 + 15, ih, "模仿者");
                button_seed = new Fl_Button(c(4) + 15, r(5), iw - 15, ih, "修改卡片");
                choice_music = new Fl_Choice_(c(1), r(6), iw + 65, ih, "");
                button_music = new Fl_Button(c(2) + 65, r(6), iw - 65 + 20, ih, "音乐");
                input_level = new Fl_Value_Input(c(3) + 40, r(6), iw - 40 + 15, ih, "2x");
                button_level = new Fl_Button(c(4) + 15, r(6), iw - 15, ih, "无尽跳关");
            }
            group_resource->end();

            group_battle = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "战场");
            {
                choice_row = new Fl_Choice_(c(1), r(1), iw - 10, ih, "");
                choice_col = new Fl_Choice_(c(1), r(2), iw - 10, ih, "");
                choice_plant = new Fl_Choice_(c(2) - 10, r(1), iw + 10 + 40, ih, "");
                choice_zombie = new Fl_Choice_(c(2) - 10, r(2), iw + 10 + 40, ih, "");
                button_put_plant = new Fl_Button(c(3) + 40, r(1), iw - 40 + 20, ih, "种植物");
                button_put_zombie = new Fl_Button(c(3) + 40, r(2), iw - 40 + 20, ih, "放僵尸");
                check_imitater = new Fl_Check_Button(c(4) + 20, r(1), iw - 20, ih, "模仿者");
                button_put_grave = new Fl_Button(c(4) + 20, r(2), iw - 20, ih, "出墓碑");
                button_direct_win = new Fl_Button(c(1), r(3), iw - 10, ih, "直接过关");
                choice_item = new Fl_Choice_(c(2) - 10, r(3), iw + 10 - 20, ih, "");
                button_clear = new Fl_Button(c(2) + iw - 20 + m, r(3), iw - 45, ih, "清除");
                button_put_ladder = new Fl_Button(c(3) + 40, r(3), iw - 40 + 20, ih, "搭梯子");
                button_auto_ladder = new Fl_Button(c(4) + 20, r(3), iw - 20, ih, "智能搭梯");
                check_plant_invincible = new Fl_Check_Button(c(1), r(4), iw - 15, ih, "植物无敌");
                check_plant_weak = new Fl_Check_Button(c(2), r(4), iw - 15, ih, "植物脆弱");
                check_zombie_invincible = new Fl_Check_Button(c(3), r(4), iw - 15, ih, "僵尸无敌");
                check_zombie_weak = new Fl_Check_Button(c(4), r(4), iw - 15, ih, "僵尸虚弱");
                check_reload_instantly = new Fl_Check_Button(c(1), r(5), iw - 15, ih, "立刻装填");
                check_mushroom_awake = new Fl_Check_Button(c(2), r(5), iw - 15, ih, "蘑菇睡醒");
                check_stop_spawning = new Fl_Check_Button(c(3), r(5), iw - 15, ih, "暂停刷怪");
                check_stop_zombies = new Fl_Check_Button(c(4), r(5), iw - 15, ih, "僵尸止步");
                check_lock_butter = new Fl_Check_Button(c(1), r(6), iw - 15, ih, "锁定黄油");
                check_no_crater = new Fl_Check_Button(c(2), r(6), iw - 15, ih, "不留弹坑");
                check_no_ice_trail = new Fl_Check_Button(c(3), r(6), iw - 15, ih, "不留冰道");
                check_zombie_not_explode = new Fl_Check_Button(c(4), r(6), iw - 15, ih, "小丑不爆");
            }
            group_battle->end();

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
                button_show_details = new Fl_Button(c(1), r(6), iw, ih, "显示详情");
                check_limit_count = new Fl_Check_Button(c(2), r(6), iw, ih, "限制种类");
                button_internal_spawn = new Fl_Button(c(3), r(6), iw, ih, "自然出怪");
                button_customize_spawn = new Fl_Button(c(4), r(6), iw, ih, "极限出怪");
            }
            group_spawn->end();

            group_others = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "杂项");
            {
                choice_mode = new Fl_Choice_(c(1), r(1), iw + m + iw + 20, ih, "");
                button_mix = new Fl_Button(c(3) + 20, r(1), iw - 45, ih, "混乱");
                button_userdata = new Fl_Button(c(4) - 15, r(1), iw + 15, ih, "打开存档目录");
                check_no_fog = new Fl_Check_Button(c(1), r(2), iw - 15, ih, "清除浓雾");
                check_see_vase = new Fl_Check_Button(c(2) - 10, r(2), iw - 15, ih, "罐子透视");
                check_background = new Fl_Check_Button(c(3) - 20, r(2), iw + 12, ih, "允许后台运行");
                check_readonly = new Fl_Check_Button(c(4) - 10, r(2), iw + 12, ih, "禁止存档删档");
                button_file = new Fl_Button(c(1), r(3), iw - 30, ih, "选择文件");
                input_file = new Fl_Input(c(2) - 30, r(3), iw + 30 + m + iw + 45, ih, "");
                button_unpack = new Fl_Button(c(4) + 45, r(3), iw - 45, ih, "解包");
                button_dir = new Fl_Button(c(1), r(4), iw - 30, ih, "选择目录");
                input_dir = new Fl_Input(c(2) - 30, r(4), iw + 30 + m + iw + 45, ih, "");
                button_pack = new Fl_Button(c(4) + 45, r(4), iw - 45, ih, "打包");
                choice_debug = new Fl_Choice_(c(1), r(5), iw - 30, ih, "");
                button_debug = new Fl_Button(c(2) - 30, r(5), 45, ih, "调试");
                check_show_hidden_games = new Fl_Check_Button(c(2) - 30 + 45 + 10 + 60, r(5), 220, ih, "显示隐藏小游戏 (Limbo Page)");
                button_download = new Fl_Button(c(1), r(6), iw, ih, "下载游戏");
                button_update = new Fl_Button(c(2), r(6), iw, ih, "检查更新");
                button_about = new Fl_Button(c(4), r(6), iw, ih, "关于...");
            }
            group_others->end();
        }
        tabs->end();
        game_status = new Fl_Box(220, 12, 200, 25, "");
        game_status_tooltip = new Fl_Box(430, 12, 10, 25, "");
    }
    this->end();

    window_spawn = new Fl_Double_Window(860, 640, "出怪数量统计");
    {
        table_spawn = new SpawnTable(10, 10, 860 - 20, 640 - 20);
        button_update_details = new Fl_Button(10, 10, 75, 18 + 3, "↻");
    }
    window_spawn->end();

    // 默认值

    input_sun->value(8000);
    input_sun->bounds(0, 9990);

    input_money->value(80000);
    input_money->bounds(0, 99999);

    input_wisdom_tree->value(1000);
    input_wisdom_tree->bounds(0, 99999);

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

    choice_row->add("所有行");
    choice_row->add("第 1 行");
    choice_row->add("第 2 行");
    choice_row->add("第 3 行");
    choice_row->add("第 4 行");
    choice_row->add("第 5 行");
    choice_row->add("第 6 行");
    choice_row->value(1);

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

    choice_item->add("植物");
    choice_item->add("僵尸");
    choice_item->add("推车");
    choice_item->add("墓碑");
    choice_item->add("梯子");
    choice_item->add("钉耙");
    choice_item->value(2);

    for (size_t i = 0; i < 20; i++)
        check_zombie[i]->label(zombies[spawn_type[i]]);

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

    choice_debug->add("关闭");
    choice_debug->add("出怪");
    choice_debug->add("音乐");
    choice_debug->add("内存");
    choice_debug->add("碰撞");
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
        game_status->label("1.0.0.1051 英文原始版");
        break;
    case PVZ_1_2_0_1065_EN:
        game_status->label("1.2.0.1065 英文原始修复版");
        break;
    case PVZ_1_2_0_1073_EN:
        game_status->label("1.2.0.1073 英文年度版");
        break;
    case PVZ_1_2_0_1096_EN:
        game_status->label("1.2.0.1096 Steam 英文年度版");
        break;
    case PVZ_1_2_0_1093_DE_ES_FR_IT:
        game_status->label("1.2.0.1093 多国语言年度版");
        break;
    case PVZ_1_1_0_1056_ZH_JA_2010:
        game_status->label("1.1.0.1056 年度汉化修正版");
        break;
    case PVZ_1_1_0_1056_ZH_2012_06:
        game_status->label("1.1.0.1056 年度汉化加强版");
        break;
    case PVZ_1_1_0_1056_ZH_2012_07:
        game_status->label("1.1.0.1056 年度汉化加强版");
        break;
    case PVZ_UNSUPPORTED:
        game_status->label("不支持的游戏版本");
        break;
    case PVZ_OPEN_ERROR:
        game_status->label("打开游戏进程出错");
        break;
    case PVZ_NOT_FOUND:
    default:
        game_status->label("没有找到游戏窗口");
        break;
    }
    game_status->redraw();

    if (result != PVZ_NOT_FOUND     //
        && result != PVZ_OPEN_ERROR //
        && result != PVZ_UNSUPPORTED)
    {
        this->keep_selected_feature(); // 重新找到游戏时应用所有已选功能
        game_status_tooltip->label("?");
        game_status_tooltip->tooltip("由于这个游戏修改技术的普遍存在， \n"
                                     "无法完全收录识别所有改版的名称， \n"
                                     "只能判断出其采用的原始底包版本。");
    }
    else
    {
        game_status_tooltip->label("");
        game_status_tooltip->tooltip(nullptr);
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
        button_show_details->copy_label("隐藏详情");
        window_spawn->show();
        cb_update_details();
    }
    else
    {
        button_show_details->copy_label("显示详情");
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
    {
        std::array<int, 1000> zombies_list = pvz->GetSpawnList();
        table_spawn->UpdateData(zombies_list);
    }
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
    {
        std::array<int, 1000> zombies_list = pvz->GetSpawnList();
        table_spawn->UpdateData(zombies_list);
    }
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
                if (name == L"." || name == L".." || name == L"Thumbs.db")
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
    bi.lpszTitle = L"选择解包文件夹";
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
        std::wstring text = L"解包完成, 文件夹位于: \n" + dst_dir;
        MessageBoxW(GetActiveWindow(), text.c_str(), L"提示", MB_OK | MB_ICONINFORMATION);
    }
    else
    {
        std::wstring text = L"解包出错.";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"提示", MB_OK | MB_ICONERROR);
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
        std::wstring text = L"打包完成, 文件位于: \n" + dst_file + L"\n\n" //
                            + L"将名称修改为 main.pak 并替换同名原文件 (事先备份).";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"提示", MB_OK | MB_ICONINFORMATION);
    }
    else
    {
        std::wstring text = L"打包出错.";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"提示", MB_OK | MB_ICONERROR);
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
    std::wstring text = std::wstring()                                                  //
                        + L"PvZ Toolkit 是一个适用于植物大战僵尸一代 PC 版的修改器\n"   //
                        + L"\n"                                                         //
                        + L"支持的游戏版本: \n"                                         //
                        + L"✓ 英文原始版 1.0.0.1051 (en)\n"                             //
                        + L"✓ 英文原始修复版 1.2.0.1065 (en)\n"                         //
                        + L"✓ 英文年度版 1.2.0.1073 GOTY (en)\n"                        //
                        + L"✓ Steam 英文年度版 1.2.0.1096 GOTY (en)\n"                  //
                        + L"✓ Origin 多国语言年度版 1.2.0.1093 GOTY (de, es, fr, it)\n" //
                        + L"✓ 年度汉化修正版/日语版 1.1.0.1056 GOTY 2010 (zh/ja)\n"     //
                        + L"✓ 年度汉化加强版 1.1.0.1056 GOTY 2012.06 (zh)\n"            //
                        + L"✓ 年度汉化加强版 1.1.0.1056 GOTY 2012.07 (zh)\n"            //
                        + L"\n"                                                         //
                        + L"版本号: 1.0.0\n"                                            //
                        + L"构建日期: 2020/03/29\n"                                     //
                        + L"工具链: MSVC 2017 / FLTK 1.3.5\n"                           //
                        + L"版权所有: © 2020 lmintlcx\n"                                //
                        + L"鸣谢: a418569882 kmtohoem\n";
    MessageBoxW(GetActiveWindow(), text.c_str(), L"关于 PvZ Toolkit", MB_OK);
}

void Window::cb_on_hide_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_on_hide_details();
}

void Window::cb_on_hide_details()
{
    button_show_details->copy_label("显示详情");
    window_spawn->hide();
}

} // namespace Pt
