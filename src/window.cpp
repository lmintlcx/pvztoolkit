
#include "window.h"

#define IDI_ICON 1001

namespace Pt
{

// 默认英语界面
Language LANG = Language::English;

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
        "搞基",
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

const char *lineup_names[] =
    {
        "[DE].双核无炮",
        "[DE].神之无炮",
        "[DE].长矛无炮",
        "[DE].群曾无炮",
        "[DE].后置三炮",
        "[DE].镂空四炮",
        "[DE].屑四炮",
        "[DE].后置四炮",
        "[DE].奥赛罗五炮",
        "[DE].双核底线五炮",
        "[DE].底线五炮",
        "[DE].无保护六炮",
        "[DE].雪花六炮",
        "[DE].后置六炮",
        "[DE].冰矿工六炮",
        "[DE].双冰六炮",
        "[DE].花园六炮",
        "[DE].云中仙七炮",
        "[DE].樱桃七炮",
        "[DE].C2f八炮",
        "[DE].神之八炮",
        "[DE].超前置八炮",
        "[DE].简化八炮",
        "[DE].瞬杀八炮",
        "[DE].前置八炮",
        "[DE].雪花十炮",
        "[DE].全场超前置十炮",
        "[DE].沙漏十一炮",
        "[DE].神之十一炮",
        "[DE].守钉耙十一炮",
        "[DE].守城十二炮",
        "[DE].撞南墙十二炮",
        "[DE].挂机十二炮",
        "[DE].雪花十四炮",
        "[DE].中开十四炮",
        "[DE].守全场十四炮",
        "[DE].连拦十四炮",
        "[DE].十四炮",
        "[DE].十五炮",
        "[DE].空炸十六炮",
        "[DE].十六炮",
        "[DE].十七炮",
        "[DE].十八炮",
        "[DE].十九炮",
        "[NE].无神无炮",
        "[NE].十一格无炮",
        "[NE].超后退无炮",
        "[NE].小无炮",
        "[NE].小楼梯无炮",
        "[NE].双七列曾神之无炮",
        "[NE].群曾无炮",
        "[NE].减速无炮",
        "[NE].冰雨无炮",
        "[NE].压制无炮",
        "[NE].双六列曾神之无炮",
        "[NE].双七列曾神之一炮",
        "[NE].变奏一炮",
        "[NE].小二炮",
        "[NE].双七列曾神之二炮",
        "[NE].瞬杀三炮",
        "[NE].土豆四炮",
        "[NE].前置四炮",
        "[NE].小梦四炮",
        "[NE].后置四炮",
        "[NE].神之四炮",
        "[NE].倾斜四炮",
        "[NE].智商五炮",
        "[NE].压碑五炮",
        "[NE].神之五炮",
        "[NE].底线五炮",
        "[NE].神之六炮",
        "[NE].镂空六炮",
        "[NE].快六炮",
        "[NE].全梯六炮",
        "[NE].雪花七炮",
        "[NE].瞬杀七炮",
        "[NE].美学八炮",
        "[NE].简化八炮",
        "[NE].生死劫",
        "[NE].前置八炮",
        "[NE].放羊九炮",
        "[NE].请君入瓮",
        "[NE].核代十炮",
        "[NE].九龙阁十一炮",
        "[NE].十二炮",
        "[NE].舞夜惊魂",
        "[NE].守钉耙十三炮",
        "[NE].丑十四炮",
        "[NE].十五炮",
        "[NE].十八炮",
        "[PE].最简无炮",
        "[PE].伪无伤无炮",
        "[PE].自然控丑无炮",
        "[PE].火焰无炮",
        "[PE].后退无炮",
        "[PE].超前置无炮",
        "[PE].王子无炮",
        "[PE].机械钟无炮",
        "[PE].神之无炮",
        "[PE].石英钟无炮",
        "[PE].靠天无炮",
        "[PE].压制一炮",
        "[PE].小二炮",
        "[PE].火焰二炮",
        "[PE].核武二炮",
        "[PE].分裂二炮",
        "[PE].方正二炮",
        "[PE].经典二炮",
        "[PE].冲关三炮",
        "[PE].太极四炮",
        "[PE].全金属四炮",
        "[PE].方块四炮",
        "[PE].青四炮",
        "[PE].水路无植物四炮",
        "[PE].方四炮",
        "[PE].神之四炮",
        "[PE].双核底线四炮",
        "[PE].经典四炮",
        "[PE].火焰四炮",
        "[PE].底线四炮",
        "[PE].传统四炮",
        "[PE].半场无植物五炮",
        "[PE].散炸五炮",
        "[PE].心五炮",
        "[PE].陆路无植物六炮",
        "[PE].水路无植物六炮",
        "[PE].青苔六炮",
        "[PE].禅房花木深",
        "[PE].神之六炮",
        "[PE].玉米六炮",
        "[PE].空炸六炮",
        "[PE].超后置六炮",
        "[PE].方六炮",
        "[PE].蝶语",
        "[PE].一勺汤圆",
        "[PE].间隔无植物七炮",
        "[PE].玉兔茕茕",
        "[PE].无保护八炮",
        "[PE].树八炮",
        "[PE].全对称树八炮",
        "[PE].矩形八炮",
        "[PE].神之八炮",
        "[PE].阴阳八炮",
        "[PE].浮萍八炮",
        "[PE].后置八炮",
        "[PE].饲养海豚",
        "[PE].玉米八炮",
        "[PE].经典八炮",
        "[PE].花海八炮",
        "[PE].C2八炮",
        "[PE].分离八炮",
        "[PE].全对称八炮",
        "[PE].3C八炮",
        "[PE].⑨炮",
        "[PE].方块九炮",
        "[PE].C6i九炮",
        "[PE].心九炮",
        "[PE].轮炸九炮",
        "[PE].②炮",
        "[PE].六芒星十炮",
        "[PE].六边形十炮",
        "[PE].方块十炮",
        "[PE].斜方十炮",
        "[PE].简化十炮",
        "[PE].后置十炮",
        "[PE].经典十炮",
        "[PE].六线囚尸",
        "[PE].斜十炮",
        "[PE].魔方十炮",
        "[PE].戴夫的小汉堡",
        "[PE].鸡尾酒",
        "[PE].一勺汤圆十二炮",
        "[PE].玉壶春十二炮",
        "[PE].半场十二炮",
        "[PE].简化十二炮",
        "[PE].经典十二炮",
        "[PE].火焰十二炮",
        "[PE].冰雨十二炮·改",
        "[PE].神柱十二炮",
        "[PE].神之十二炮",
        "[PE].水路无植物十二炮",
        "[PE].纯白悬空十二炮",
        "[PE].后花园十二炮",
        "[PE].玉米十二炮",
        "[PE].两路暴狂",
        "[PE].九列十二炮",
        "[PE].梯曾十二炮",
        "[PE].君海十二炮",
        "[PE].箜篌引",
        "[PE].梅花十三",
        "[PE].最后之作",
        "[PE].冰心灯",
        "[PE].太极十四炮",
        "[PE].真·四炮",
        "[PE].神棍十四炮",
        "[PE].神之十四炮",
        "[PE].穿越十四炮",
        "[PE].钻石十五炮",
        "[PE].神之十五炮",
        "[PE].真·二炮",
        "[PE].冰箱灯",
        "[PE].炮环十二花",
        "[PE].对称十六炮",
        "[PE].神之十六炮",
        "[PE].裸奔十六炮",
        "[PE].双冰十六炮",
        "[PE].超前置十六炮",
        "[PE].火焰十六炮",
        "[PE].经典十六炮",
        "[PE].纯十八炮",
        "[PE].真·十八炮",
        "[PE].冰魄十八炮",
        "[PE].尾炸十八炮",
        "[PE].经典十八炮",
        "[PE].纯二十炮",
        "[PE].空炸二十炮",
        "[PE].钉耙二十炮",
        "[PE].新二十炮",
        "[PE].无冰瓜二十炮",
        "[PE].绝望之路",
        "[PE].二十一炮",
        "[PE].新二十二炮",
        "[PE].二十二炮",
        "[PE].无冰瓜二十二炮",
        "[PE].九列二十二炮",
        "[PE].二十四炮",
        "[PE].垫材二十四炮",
        "[FE].无神无炮",
        "[FE].两仪无炮",
        "[FE].十二格无炮",
        "[FE].太极无炮",
        "[FE].水路无植物无炮",
        "[FE].十二格玩具",
        "[FE].间隔无炮",
        "[FE].方块无炮",
        "[FE].热核无炮",
        "[FE].半边无炮",
        "[FE].茶壶无炮",
        "[FE].神之无炮",
        "[FE].心无炮",
        "[FE].火焰无炮",
        "[FE].智能无炮",
        "[FE].后退无炮",
        "[FE].塔曾无炮",
        "[FE].顶满七列曾无炮",
        "[FE].无冰瓜一炮",
        "[FE].火焰二炮",
        "[FE].大雾二炮",
        "[FE].压制二炮",
        "[FE].最简四炮",
        "[FE].鬼位四炮",
        "[FE].落月四炮",
        "[FE].帆船四炮",
        "[FE].神之四炮",
        "[FE].磁铁四炮",
        "[FE].雾四炮",
        "[FE].玲珑六炮",
        "[FE].烈焰八炮",
        "[FE].无保护八炮",
        "[FE].神之八炮",
        "[FE].经典八炮",
        "[FE].河洛十炮",
        "[FE].斜方十炮",
        "[FE].纯十二炮",
        "[FE].水路无植物十二炮",
        "[FE].神之十二炮",
        "[FE].曲径通幽处",
        "[FE].礼物盒十四炮",
        "[FE].某十四炮",
        "[FE].弦十四炮",
        "[FE].半场十四炮",
        "[FE].奇门九劫",
        "[FE].灯笼十六炮",
        "[FE].花环十六炮",
        "[FE].中压制十八炮",
        "[FE].无冰瓜十八炮",
        "[FE].十九炮",
        "[FE].二十二炮",
        "[FE].二十四炮",
        "[RE].无神无炮",
        "[RE].群曾无炮",
        "[RE].水晶杯四炮",
        "[RE].#四炮",
        "[RE].波纹五炮",
        "[RE].小六炮",
        "[RE].分隔六炮",
        "[RE].方三角六炮",
        "[RE].*道六炮",
        "[RE].神之七炮",
        "[RE].方块八炮",
        "[RE].斜方八炮",
        "[RE].理发八炮",
        "[RE].沙漏八炮",
        "[RE].#八炮",
        "[RE].螺旋十炮",
        "[RE].镂铭灯",
        "[RE].天台十炮",
        "[RE].花灯十二炮",
        "[RE].椭盘十二炮",
        "[RE].鸟居十二炮",
        "[RE].天台十二炮",
        "[RE].椭盘十四炮",
        "[RE].十六炮",
        "[RE].十七炮",
        "[RE].十八炮",
        "[ME].无神无炮",
        "[ME].核聚变无炮",
        "[ME].群曾无炮",
        "[ME].长矛无炮",
        "[ME].双核一炮",
        "[ME].神之五炮",
        "[ME].神之六炮",
        "[ME].底置六炮",
        "[ME].无蘑菇七炮",
        "[ME].对称八炮",
        "[ME].奇怪的八炮",
        "[ME].田八炮",
        "[ME].轮回之瞳",
        "[ME].分隔九炮",
        "[ME].无保护十炮",
        "[ME].月夜十炮",
        "[ME].瓮中捉鳖",
        "[ME].十三炮",
        "[ME].十八炮",
};

const char *lineup_strings[] =
    {
        "LI5HDH3kARQDFMNVWlAyXvhBVN360d/4UBcwRTg+hJhVVLXDWrRU",
        "LI43NBRTVn9Rgl44QQzfdmZH3ONm+BEF50ZwUvCDZjRRVFowX/lU",
        "LI5HDH3kARQDFMNVWlAyXvhR3vlBDF9DDV3RJAX4PoSYVVR08kQKVA==",
        "LI5HDH3tBib/1HpXSFyYwAhfQI1+5MI1eQAwcUSOXNSRUIK2Btc6WlTc/0bzVA==",
        "LI5HjH7tAiZ/lxVSbEQMfW0HJnGXAtLhJEVPdoA0zFdUQ0pboFQ=",
        "LI43jH/tASbxsALS11hk5MPVVZwzFELV/uVVFhY+tHZUWD1bsFQ=",
        "LI5HjH7tASbx1HrXeldAXJjACF9AjX7kQlCVdmIU7EbQTQIWgfgxbFzwWmaUVQRaGVBUYCxbMlQ=",
        "LI5H5MUIf+3BtXRXSFyYUN74MIye5EJ6UMDBeBEF50IJ2dTZsBgAJ1SYb1otVA==",
        "LI435DU0xAiflJQkxFVSFPjpVn/VsB78XAQKJnFVYSK8slRUfQ9fLVQ=",
        "LI43bJyUdOQCNHGXHlJMVN4c+kEMn+RBnCJUFtycHuTOwQyAlBEEmVVUq+dblVQ=",
        "LI43bJyUdOQGNHFXV9dZlwJSRFTd+FHeVWWXDuwcd0yOdN34UaZ1aDBhDzVWVGL6RDRU",
        "LI43bJyUlORD3BVgUIxk+FHf+FAWXGzcErcG1zZaVBScX6VU",
        "LI43NDQ0xAh97cG1dFdIHPrByH3txlV1MnftQFw3lajXbIA0zFdUtwtb51Q=",
        "LI5H5MUIf+3BtXRXSFz4wcjdflY2H8L2/RWD4UYJQ1TLmlnoVA==",
        "LI43NMQIf+0GJnGXAtLXWERU8HEzHjox5NXf1ID4Ud9ktAHXNlpUQapEx1Q=",
        "LI5H5MfIfe0GJn+XFVJ8RAx/7UJ80nBWNh2SHsJ2/c1dANf+n1IJQ1R5i0T7VA==",
        "LI5H5MUIf+1GXINejGTU1ZQO0tcUvnTMUUUNXUMN3QdZ0m1UReFEaVQ=",
        "LI43NDTkxQh/7cKV0lVSAmZIUMZTlXhcbNzQJf1VVuRtJFRUakdfKFQ=",
        "LI5HDH/tAib/sALS11hkVDDVkER2VnRhf3ED1hBQgrYF1zZaVNQRRiZU",
        "LI5H5DVsnJRUkgR0NJfkQpgLXUMNHdBOWCdUWbFeylQ=",
        "LI43NJRUU01McIMe+lCFNFhFzV1B5Tfklf5SV1RUXARfU1Q=",
        "LI43bJyUdO0CJn9XxFI3ZF1Azd1y5kb+Ul4UfnDjXvgwzF1DDV0GdzSXNFe1V1QHeUVDVA==",
        "LI43bJyUdO0CJnFXxNJWT53hNE51JkTZkvVSgUhUSQZfSVQ=",
        "LI43bJyUdO0CJnGXGFJPUlzU3Ugw1FVPdGhcxZX9UpdIVOB6Wh9U",
        "LI43bJyUdO0CJn9XxNJWT3Qrct5cHJkencFQgfTMV1SujFvtVA==",
        "LI43NDQMnyTE1VXYdZRSkMIIn+RGelL2A1b1WQhYB1nSbVT/Z1omVA==",
        "LI43NMQIfe3C1dW1dEBX1bAOnc38dlZ/UThc/RVjU1TxQVrEVA==",
        "LI43bJyUlFSXRDRXs/vQ34wUrX8l/pVkU1RuvV+0VA==",
        "LI43NNRWT0zXtXRX17AOncF0TthNtHgodkyyVFSlLF4YVA==",
        "LI5H5DXMneRDXONmSDBUV9Xhxj9x4x6aMOTV3dQ8ncHGf5Wo1yTF4RRhvHYcPlTFqEd3BA==",
        "LI43bJyUlFSX3VhYHGjQ3FlM+lAXCD5kEFTSOFn1VA==",
        "LI43bJyUdO0GJnFXxFI3ZH3tAiZ5xtxZ19nweFBmcrYE1zVaVE2WRItU",
        "LI43bJyUdO0CJn9XxFI3ZF1HxQh/5EJ+5gYmcQCQUvNOQCdUmXBArVQ=",
        "LI43DJ3kxrV0V1dMF1TWW0dv3NJNTDhkgIx03dVVVPcZWWpU",
        "LI43DJ3kxrV0V1dIZ2Q03oxUdX5s3NLl3FRU85BZ/1Q=",
        "LI43bJyUlNTYdbAefBBCNVTHXEVPUm9kEtz0zFdUpKZbLVQ=",
        "LI43bJyUdO0CJnlXxFI3ZN1+duRGVsUQOLQ43Ep4dlQkBUV3VA==",
        "LI43bJyUdO0CJn9XxFI3ZN0RMPGwHlJPfEvDTkBFVDttRstU",
        "LI43bJyUdO0CJn9XxFI3ZN0RMHFFPgQQVNMYR2RU",
        "LI43bJyUlNTYBS1ERVJST9XBRJw01xdZ0lxUhmRbOVQ=",
        "LI43bJyUdO0CJnFXxFI3ZH3tApRSAVBRtwTXPlpUeLVFEVQ=",
        "LI43bJyUdO0GJnFXxFI3ZH3tAiZ5/tzU2dRZ/lxeknZWVGRCRC5U",
        "LI43bJyUlFSXf004xCyMERTMfEVUgwBbCVQ=",
        "LI43bJyUlNTYBS3Mdn9NONTEXAlUh0hbIVQ=",
        "LI5H/MDIfe0GNP+UAlIJUmRE/FAWYEWdHiBhzO5wA/beVFQkQ0YXVQ==",
        "LI43NBRTVn9Rgl74MAzfdmZHfNYDWXJUVN7OU4BV",
        "LI5HDH3tBib/1HpXSFyYQAx/5AE0ecZcEJkeMGHGP3Hl/RVmU1TvjFmlVQ==",
        "LI5HDH3kAjTxlALV4VgEVLCZULbBfHY/xQFEU1TqSF5vVQ==",
        "LI4ZnuVZVGRcVxUSJL91TMxFfAgu68QcxaymoDxc2kGYNnbDYM8y0sI8kITjxe5DkqS4VPklRWVV",
        "LI43NBRTVj9xgx76wIie5AE0+ZQO5Jwenc0UxcFYD00CtgbXXVTrbFqGVQ==",
        "LI5HDH3tBib/8HrXeldAXJjACF9AjX7kwjV5ADBxBFD8HlR8cuRC805gJ1TueEflVQ==",
        "LI5HDH3tAib/8HrXeldAXJhQ3zhBDH/kQn7mBkZYUeKWEeT9FWdTVMu7R1hV",
        "LI5HDH3tAibxsAJEQAyfVFBWZ9V2DwUQFKbQgfTNV1SsS09dVQ==",
        "LI5HDH3tAib/8HrXeldAXJjQ3Fz4MQxfQQ19XdJWD1GCXviR/VKZSFTSgEbNVQ==",
        "LI43NBRTVj9xgx76QAx/5MI1eQAw8bAY9Jwe1fk0Bfg+ZFVUyMtZqlU=",
        "LI43NBRTVj9xgx76wIh+5AE0+ZQO5Jwenc0UxcFYUyX/lVBU/uVaAVU=",
        "LI5HDH3tAgYDFMMVw1VeUDJWEQJe+EAMn+RCfiBEfA5eQDVEDH9UQkcM3/oSNPGwGAAnVHByRMRV",
        "LI5HDH3tAiZ/lxVSbEQMfW1HFzD5sB7VwVY/TRxUVNxjXZRV",
        "LI43NBRTVj9xgx76wIh+5AE0+ZQO5IQVUlL0nB5E2QdZUlRU3O5Z/1U=",
        "LI5HDH3tAib/1HrXeldAXJhADH/kQVyDXvjR3vgwjJ4kRBx3/TUMX0INX0OVBFdUUHRamlU=",
        "LI43NJRQxj9xAx76MGxcQ1TlEHHj1r3hbIA0VFTgkF19VQ==",
        "LI43NMSIXtZYU020FCb5sBhgxcF0nGTHNXlKYTyyVFSoaVulVQ==",
        "LI43NDQ0xAh97ca1dFdGxAh/bcc1cZcOcPXXBNgTWf5tVHR8X/1V",
        "LI5HDH/tASZ/lxVSbETMfe1CGTDxcEReODEM3xNZ0m1UQ2ZbtFU=",
        "LI43NJRUU01McIMe+lCFVj+VdmcVKJ3NWH9N4hYRZIE0VFQfqVgpVQ==",
        "LI4RnGVFVGRYFgVw5HZ21n/1VzdQgA3HWr1L7C+E5gbPMrb0/4GCY7zikqFof7wtQseVlCBVoZlGZlU=",
        "LI43NFRVncFYU00EVLF2VAjJU8RV",
        "LI43NMQIfe0BJr/W11NMWmQU1LAOnc08dn8V/lz+FWVTVOJUTlRV",
        "LI43NJRUU01MUIJe+FGFXEWdwcYPlWZ/FVZWf3GDVrUecGFMVFS7Y17EVQ==",
        "LI43bJyUdORGWONmFFQcMHlE+kAM33CGXNK8Pk4l/1VUGTBFClU=",
        "LI43NJRUU01McIMe+jEMXTaVEQIe+jCM3nbW/lJXVFRG/V9+VQ==",
        "LI43bJyUdO3C1RU2f1fEUVV06rAe5ExQSNCmA0YE1zZaVMT+WY5V",
        "LI5HDH/tAibysALS11gEdGRHfOZGDVCQxtjBeBEGF9B6VAgLRdtV",
        "LI7HCH/tAib/sALS11gEdN11VjYd+sAI3RtZ8lxUxwtG/1U=",
        "LI43NDQ0xAh97cG1dFdIHPrByN12IkR2UrJLkPVSl0hUuilbpFU=",
        "LI5HDH1tBybxsALS11gEdOQCJnkEWHh25EJ4IETV1XZn5f1FlGRTVJVwQEBV",
        "LI43bJyUdO3CVU2UEALWDBDflFQIUFRgiF+RVQ==",
        "LI43bJyUdO0CJnFXxNLWzcY/lWAWsHRO2RdZ/m1UF4Bfg1U=",
        "LI43NMQIf+0GJn+XFVJMVOaEkJR2WN1TTAQRBKH1p1Vtb0UcVQ==",
        "LI43bJyUdO0CJn9XxNLWwRRq/lwcmR52gPTcVFRlsUSTVQ==",
        "LI43NBRTVj9FRH4gxNUVJvGwAkRZkkTF4cZ/ZRDEgFRUJY1bsFU=",
        "LI43bJyUdO0CJnmXAlJ0X1h0dn+VKOTMlB7VwVhcxNwZWVfSbVRwikSkVQ==",
        "LI43bJyUdO0CJnlXxNJWuHZ/cQNGANd2VlSwyFtrVQ==",
        "LI43bJyUdO0CJnlXxNJWGMXBNKIVZF/6UtpNhJD0VFTlWVjiVQ==",
        "LI43NDRsnNSURNR9lpTkRl4l/xVHVVR3cF/lVQ==",
        "LI43bJyUdO3CNXtXl9bXU0wUxFV4dm0HJn/enAKd+XROdlIBV0M11L8WzFdUHBZJylU=",
        "LI43bJyUdO0CJvKwAlJ0X1h0dj9xA/bc+NCmW3b9zd115kJ1VlQqXka+ZQ==",
        "LI43NDRsnNSUWFMUkB5kL3kQUFgEgNQBFID40N9IEANRVPTtWvRV",
        "LI43bJyUdO0CJnFXxFI3ZF1ADd9y5sZcYXyyVFQplEaoVQ==",
        "LI43bJyUlFSWf5VwV8DTCVDS3UZVVO78WrFV",
        "LI43NBRTVn9RgvbebPggzL3kRpBeDN925kV11v1fR1RUKNleulY=",
        "LI43jH/9X9ZYXOQDJvKwAvScDszUlx7TwVhPSThI4laNPzV2FOxBkNfcNL42lGRNVC9jR75W",
        "LI5HDH5d0FYfTTZN9BQ0+bAYnflW7ljuZEXTwXSc5GU0OZQOMEVTT9DclB4gCVYPcYP23lRUQEBBvFY=",
        "LI5HDH5U0ljlWAR0ZAcm+bAGHXBF08FEnORlNDmUDnBFT9Bc8npVWMdV80pNcFY=",
        "LI5HjH7kAhQDFMNVWlAyHvrBiH79n+RCcrbkRlBNYm44WQxP5EJ1tjS3NFdHlYBx1DVmVFohQjVW",
        "LI5p2JVZlGRcV2nW61iVUgWRXPjDRa6kx6lOxAaLn3ONwJ2e3lqT0DEvGHdc3OOd3walSAL4+DrnjkCvEZSpbZK9rKdVi4tIelY=",
        "LI5HDH5U1eVYL9VEXFAyXvhB5EWMXpBiWGJ0RdPBWj9JAmY4WIxONEfkQlDVdn+Vdn/VRHhWg+EBNHlXTNQMFPifVNY0VFRWb0t/Vg==",
        "LI4Z2GVFVHRYV391f3YklNTQjhcW01hYoRNfSBMqnltbe3jafgG6ZBRgbHxo8g873U7yZl1HGvIO5Fnsbw22v5Cvn19OY0/kVg==",
        "LI43NBRTVj/VJH9M+jEMX0YlDF3SD1c41CR5XDbeNL6WUFTFW02xVg==",
        "LI5HDH/kARTDVVD1FDTyVBw4eQQgeRCQNXFcZjhY5FWW4XRcRSVUplFiFhBkIV00zFhUj59OmVY=",
        "LI5HzH3tAib/sAJSCVJ8RIxeRUWEQQyf5EJwtgS9NLfkgTV/lxLV2VU/FUR8ZkcBUAfDVNKdVIfdSy5W",
        "LI5HzH3tAQYDFMNVWlCCHvpR3WX40d1s+FCW11pYVX9XglL40d+MZDhYjF5HlYBx1DVmVFo/QtVW",
        "LI5HDH3tAiZ/lxVSbEQMfW1HAZA1cVxeOFgM30RdDN+0RV9Uq2VZMVY=",
        "LI5HDH7tAib9lAbSDFJ8RMzderbkhrX0VxeUnlTP1OE8dn81dszuUGQYUlR9gEKOVg==",
        "LI5HDH3kAjTxlAJSCVJ8RMxdQA1fQA1fRyVsvJS05GE0MdRZxLmwtFRFNYxcQFX+JSQkJJbyH1SXMFR6mENAVg==",
        "LI5HzH3tASZ/lxVSbEQMf+1CAZA18Zce1dl0ApQO0NzX2dfZlJLU+VU/FQRUUONevF68ZhSBXNQYgsGAMYTRzVdUX+NCklY=",
        "LI43bJyUdOQCNPGUAlJPUlxU3hz6wVDd+NFcbJggDL/kZjQ/lJ5U/FyXEiBF1c10acYPUSA17lDCHtY0eARQPmZU9XNNfVY=",
        "LI5HDH/tAQYDFMNVWlAyHtaRTIKWEEgCZjggbLyURDRH5GI0eRBQXBV2DzV2zO5QZBhSVL1zQaRW",
        "LI5HDH5U1uVY8VgEdGQHNPnU2ZQCdO1CdrbkhjX5lxVTUtXZVX9XgtZ03NN+1v1fmIJBhDGMX2dNVBODSMxW",
        "LI43NFRVncFYU03E1LAOUk9SQGXT11pYWn9NVleC9t5R+DB0TlRUyu9d9lY=",
        "LI43NMSIfu3B1dW1dFdIHPrBCN9+lvRZ0FhYzhTcB1AHQ+6dVDZmXvFW",
        "LI43NJRScIMe+jBs3Hi2JITVdZRyNHlqRRgJ/FRUYSpec1Y=",
        "LI43NDQ0xMh9ZMdVXRz6wQh95AY0edi75EZcOUg4VgJS+NDe+FHeSCA0VN6UAWVI0DYw1JZTVLkbRDJW",
        "LI5H5MXIfe3GtXRXSFz4wQh/7UEN0EzU/R80ce6dVMPfX8BW",
        "LI43NDQ0xAh97cZVXRz6wchd0D81KNPXWlhaYhRc8CXdNL42lGRNVNuRW4lW",
        "LI43NJRQxj9xMx46MQxft29IIFS31MEU7ELvXPJ6GFRU5c9EnVY=",
        "LI43bJyUdOQCNHmXAlJSUlNSRFTeHPpBzF1GRSRU3W2YIAy95GZUXBWGWnRFTzBFIAlcReydNFRUUexBjFY=",
        "LI43NMQIfe3BldJVXRz6wchdQA9ft29IIFS3VM/U4Tx2f1eCtoaR1DVmVFO7RlZW",
        "LI5HDH7tAib9sAbSDFJ8RMzderYkhFXYVwJSjFD4EUcNXUWVgHHUNWZUGEZD+lY=",
        "LI43bJyUdO0CJvGUAlIJUlyURCUMvWSHNTHU2ZSS1MFVP8URVuJS+NHc1CBd+EGMfvTfOFr+XFQj00OhVg==",
        "LI5HjH7kAjT/1HrXeldAXJhQ3vhBDH3kwTV5EJC19FdMU/hY5F0MX9Ycdg91dszuUGQYUlR6YUggVg==",
        "LI5H5MUIf+0GJn+XFVJ8RNTc+BDcbEgg1LfU4XScFEJUVEgKWSFW",
        "LI43NMQIXtZY5VgkdOQCNPKUAtLhZOqXFVNkWoxO5GI0eebclJLUzVViRAHGP3EzHjoxDN2Ec+1GXONmSNClVZiCQgxW",
        "LI43NMQIf23H1RU08ZQeUlxsnFRGj172UYLWUEg4SFpuZNQklJ7U4UQRWj8VKNXZZGpcHJrAiH7UtLtRFlIdCdBoVO/lR89W",
        "LI43NHRYSFpulCWUHnQI330W0GVYVIQCWTFW",
        "LI43bJyUdO0CJnFXxNJWGEV21NRZ7kr0nBid+Zx2VPkWX2NW",
        "LI43NDRsnFSVXOQGJvmwDtLBZPqXHlNP09daWBQmcXpFGAlYTHJXVJx9RINW",
        "LI43NDRsnFSVXGQHJvmwDtLNZPqXFVNS08EUXPD1dn9JOJT2Ylp/Jb1W1sE0J7V+VIfTRSVW",
        "LI43NJRQxj9xMx46MWxct29IIFS31MFVYlU/5d80vpZQVNmXRENW",
        "LI43NMS4URVSRNBWneHGZ3HjZkjQpUlabtQllB50CN8JUAdDV9KdVEV/Q11W",
        "LI43NMQIXdAPTcTUsA6dzRTF4WTqlxVTXApN5GI0ed7cGVREFsFJ0DZQDJ9kx5VSlVFUGfBFkVY=",
        "LI5HDH/twbV0V0ZEzH3tQgGQNXFESiA0XORdDN8fUAfDVNKdVHrIRmVW",
        "LI43NDQ0xIieJMRVXRz6wchdQIcxDF+1b0ggVLfU+VVnV4I2Q5WAkdQ1ZlQmKEBtVg==",
        "LI5HDH/txlVYcAJe+FGFVj9xM9aQcAIemNDcbEggNNwMTTRH5UaQ1t1Q+NjkXdTfVJUV9MrNdEZVcIIWZFBUVH3cQWdW",
        "LI43NDRsnJSU5MZVVXSo11xV09daWFp/FXBcULzWkUSo4XQGNHnX2bACnflYYlY/Na5QghZ02FtUJ+NFc1Y=",
        "LI43NJRUU01McIMe+lGFNNhRbEggNCQMXXLVTFPkVc7mBiZxjFhPxFRUE0Vfq1Y=",
        "LI43NFRVnfnGD00E1LAencFWPzVo09daNNiWC11FJeRVX0lQtsE0xtWVUv64dEZdUFRPflpkVg==",
        "LI43jJ/kw9XVNX+XFVJM1N2YMAxfRSRsvFST7BBkIWU0zFhUx7hABVY=",
        "LI43NFTV0h5SQITk4jUylw5Qi7X0V9eXHkTdlgvdeJIkRPw7ctwQto/UdBhYVIKyRzJW",
        "LI43NNTU0h5SQITk4jUylw5Qi7X0V9eXHkTdlgvdeJIkRPw7ctwQto/UdBBYVORIRzJW",
        "LI5H5MUIf+0GJnGXFVJ8RJREJWy8VJPsENxVVHJSWmFW",
        "LI43NJRQxj/VJH+XFUyLtfRX15cYZF2QjBFkITVWVCQ/WztW",
        "LI43NMSIfu0GJnnXWVdAXDjBCH9tByZxBDB5EJA18ZcYdOIlbLxUAbfkQpxTpkR2WFPFZO5MQFRU/iFHVFY=",
        "LI43bJyUdO0GJnFXxFI3ZH3tAiZ5xlwFVPiTUg3TsAL07Rx2VHKpWPlW",
        "LI43NMQIf+3BtXRXRsTI3X62JIRV2FcyUvgRR41eR5WAkdQ1ZlRFJEZNVg==",
        "LI43NMQIf+0GJn+XFVJsVKYzdt9QmCBsvJRUllVnV4LWELSo+RSN4QQJZwUZNVTN2HZWVIR3QNJW",
        "LI5HvMEIf41/jZ+EnyTEVVhQZBBIWm4UpB5TT9PBjBFQ3GRTVPknTcFW",
        "LI43NMSIXtZYU020FCb5sBgwRdPXWjRI5GE0MpQOYMXBREUYCVhMcldUcSdDG1Y=",
        "LI5HDH1d0lhTTUxMAlZl15QeneEU3HC25EZeW25k1CTUWfJc8npVWMdVgpZLTVY=",
        "LI5HDJ8kxNVV2PUUNHmXGGQreRiQlZo18ZcVU9LUwVUEZVNPIEUYCVZMcldUCDpHFVY=",
        "LI5HzH3tAiZ/lxVSUFTmlTbuFFxSWlNJTEiC1pzU+VU/5d80vkaUZE1UrtxCaVY=",
        "LI43NDQ0RAx/5MY1/5Qe1eFYBNR+tiSEVdbjlg1MdlgQzFdU9XdOI1Y=",
        "LI5HjH7kAjT/lALS11hYWC/VzBU0cgwwchaQtfRXTFP4UJbhdNx91v0fVJcwVFwNdNtW",
        "LI43NFTW1wRYV1MFPdPBFCyE1VXQRXY0TnqWNFfQ/PJk9KdVVHJYMlY=",
        "LI43bJyUlFSXRNR1tiSEVdr1dn/VhFJc1WBXhVRU0MJYslY=",
        "LI43NJRQxj9xAx76MMydNFe1b/ggzF2QU0lMFEx4NlfSHHYEJETeBS0ERVQO2URcVg==",
        "LI43NDQ0xAh97UEcSTDUVp3hxmdxA9atBGXTwVpTSUw0TAlYVXAzdhjVV09MV1RGLVuAVg==",
        "LI43NMQIf+3BtXRXRsTI3X625IG19FdXXFP4IcxdQtWmdTZVP5Xugva/xwhe0OVcRVTbgkEPVg==",
        "LI43NDRsnFSVZCRE2TIkDF1yW25kbIx0EBQoUuxclx7sLk9wqXwyV1T2O1huVg==",
        "LI43NFTW11ictHRG0lbT11o02JoTQjcMXYI1l9R45kac099UVO0lWO5W",
        "LI43NJReWhZlQGxIIDQkDL00V/ZFKGRfelIC68aVUg1L/m1U3CdZblY=",
        "LI43NHRYSFpuFKQeU08IdlhTxWRaRVRy/lgBVg==",
        "LI43NFTX11j8tHT+zJcVU1JTT3RQhoysjKA0zl9U2ZBfL1Y=",
        "LI43NNTW11i8VHq2JIRV1QNujDRHNXSWSFS2FlkBVg==",
        "LI43NMQIf+3BtXRXRsTI3X62JIRV2iXdNL42lGRNVJ3ZROdW",
        "LI43NMQIf+0BJn+XFVJsVKYzdt9sSCAUtBC4dszuTGQYUlTsWEF5Vg==",
        "LI43HDCMf+0CJnFXV5cVUmREHMLIXUAPfe1BcrbEvCSE1VXSV9Q+V8aFEUxGhSFdcPfPWFTh+05VVg==",
        "LI43bJyUlNTYBS0/FVZaU0l0jNLVdZRSejZX1hRF5E5SUp3hxmdxA2YULTTFwXTctFdUY/lGClY=",
        "LI43bJyUdO0CJnlXxNJWWMXUwVV/SVpu1D0IdlgQzFdUWy9C11Y=",
        "LI43NDRsnFSVZCTEVReYNXFQlq1TSbRMWjj0RPNtVGscWjRW",
        "LI43bJyUlORGXBVgUNQMYhRcQyVsvJS05EZc1WDeTEZL+kfJ23BSVMT2WbxW",
        "LI43NDRsnJSU5MZVVXSo11xV09daWFp/FXDQWUIXt9eBj1S1FWDHxKxUJDFbfVY=",
        "LI43NFTW1wTYVDx2WlNJTEgCVnXEEraPVHUIWPgqcURKkDFaVNIpRK9W",
        "LI43bJyUlNTYBS00RdPXWnxMfOZGVlc4dMTVfFRU0eBEtVY=",
        "LI43NFRVncFYU9WAFVJsFEIlbLzU1lc4ZBFM3FRUrh9b/VY=",
        "LI43NMQIf+0BJn+XFVJsVKYzdt9sSCAUlYwQZCFlNMxYVKJYQjlW",
        "LI5HDH7tAib9MHiXFVJ8RAx+bUcBkLX0V16Sctb9H1SXMFQdl0P1Vg==",
        "LI5HjH5tByb/cMwwbJxUUFYPcYPWEeKWEEhabvS01MHMdszuUGQYUlQZQXX/Vg==",
        "LI43NJRUU01McIMeOlGFNJi0JITVlTX5lwJkWZCMEGQhNVZUc0RGrVY=",
        "LI43NJRUYsY/1SRxlxV0T9BNSFpu9DQ4dszuZFVUrGNGdVY=",
        "LI43bJyUdO0GlNJVHNdlzMAIf+1CHdBM1P1flzBUSzNaFVY=",
        "LI43NIztIrOeyQ9DSDDUV/ScODDF0Nf8TM9c8npSWMdVqLZLHVY=",
        "LI5HDH1d0lhTTUyUzBU08bAOdBBGJQxd0VNJTBRslFIHUAfDVNKdVL3WSy1W",
        "LI435MW4wQhfkOlY6VhTTRQ0ce7clxVTQEjkRgdQB0NX0p1UJoJJiVY=",
        "LI5HDH7kAEZcUZTEdcLV1bV0V9ewDp3hdE7YTUhabmRs+CDkVYcUSNQRUAfDVNKdVDTSSQdW",
        "LI43NJRScIMe+hGkSFpudORZ0pwYRJ0kRP5fHGeM1B0wRWRUVBSURpZW",
        "LI43NMQIf+0BJn+XFVJ031VY1KjNnHZaU0kEZGJFGAlYTHJXVMV7TdFW",
        "LI43bJyUdO0CJnlXxFI3ZN1+tjST9J30WZdaZ9V2Z0UoUhn0aEIJzHZUAzZHt1Y=",
        "LI43NDRsnFSVXFS2jXTfb0ggNCTkJQxd0BRC3lzA2/ZfDVDdW1TDNVutVg==",
        "LI43NFTX11j8tHTmzJcVU0DYGVD+KnFEds8xV0Ll1SRUCm5EvlY=",
        "LI43bJyUlFSWYjTGVZ5Xtc0kRWQkDF3QU0kk3TS+lmRNVPidRIlW",
        "LI43bJyUlFSXZNSSI2y8lLQ0V9AUTsNcSge0NlQcYVorVg==",
        "LI43NFTW1wRYV3SiHlJPzMyXFVNSU09k7UYQFhECdpC17jjUroQZ1qdVoCFGd1Y=",
        "LI43NFTW1wRYV3TiWRaQtfRXfuKVQNX8wAjdNlrOXFSXIUUTVg==",
        "LI5HDJ0kxNVV2PUUNHkIkFp2tiSEVdol3XS95tXeNMxYVLV/RKFW",
        "LI43NNRWT0zXtXRX17AOneF0TthNSFpu9LTUwcx2zO5MZBhSVASIQEVW",
        "LI43bJyUdOQCNH9XzDJUVVhF09daJEjkRlxHZRFM3GRTVKtHT4VW",
        "LI43NFTX11j8tHT+zJcVU2wSsxeRApahlKCNdN3VVVR1GkQKVg==",
        "LI43NDTkNVRVXF1WU01McIMe+lGFNJi0JIRVUVP4kEDV/9K/llBUBHVHElY=",
        "LI43NDRsnNSUWDxgzLnkRlhbbmTUZAyQkjVyZktcOASYFIJbQ1NUWYJGCVY=",
        "LI43bJyUlNTYTUwC1j1PdGhcsmVsSCA0JOTVFnRPz1zyelJYx1XkQEHRVg==",
        "LI43bJyUlNTYdbAefFDfbEggNCQMvTRX0H8VODh2zO5MZBhSVD8vTLlW",
        "LI43NFTW1xToRhiWVN7clxVTXOLV52QQTNxkU1Rj1Ef5Vg==",
        "LI43NJRUU4Vk15cVUwA4133W/V9HVFTlfUVdVg==",
        "LI43NHRYSFpu9LRUTxhF0tcU0ZzMVQdQVImORX1W",
        "LI43NNTW1wSYlDRz7QIm8rAe0NyXFVNA2BnQlVIJQ1fSnVTY7ECrVg==",
        "LI43NDSMX9JTTUyUTFxwgx6awAjdRCVsvNTW5d1kjFUh+dC+1Mw3V2JRHVBUC6dDrFY=",
        "LI5HDH7tAib9MHiXFVJSZDJElEQlbLzU1lcCNtyMXEQ1WlRgAUgGVg==",
        "LI43bJyUdO0CJnlXxNJWWEXT11p8TM9cV0WyVFSl5EIVVg==",
        "LI43bJyUlFSXRNR1tiSEVdUDNkM1dJZIVEkURjFW",
        "LI43bJxUVlP1TM05V9A0ZdPXWgRGlhbkSQJWdRBY8j9xRHaYEGVNVBBEQHtW",
        "LI43bJyUlNTYBS00RdPXWnxMeOKGlVLSTUxkoDVBVVTbaUeWVg==",
        "LI43bJyUlFSXRNR1tiSEVVE3R1X9wgh/7UL4P3lXFjByDDB/HFRUJdxBrVY=",
        "LI43NMQIX9APTVpmZNRlzBBBJWy81Nbl3TS+NpRkTVTbWU07Vg==",
        "LI43bJyUlFSXRNR1tiSEVVFT+JBANXSWSFTNaEFTVg==",
        "LI435MUIf+3G1dW1dEBnZIwcmhBBJWy81Nbl3ZQBd5iVRFVUqrxC3VY=",
        "LI43bJyUdO0CJnFXxFI3ZF1ADd9EJWy81NZXOGQRZCFlNMxYVO3jTgF2",
        "LI43bJyUdO0CJn9XxFI3ZF1ADd9EJWy81NZXAjbcjDS+NpRkTVSCNk6OVg==",
        "LI43bJyUdO0CJnlXxFI3ZF1Azd1EJWy81NZXAjbcjDS+NpRkTVSedk72Vg==",
        "LI43bJyUlNTYBS00RdPXWnxMfuaGNXkMgtLVdTRxV0WyVFTp8kH1Vg==",
        "LI435DUMf+0CJnGXFVJSZFLH/HZaU0kEJNRZ8lwIYd5t/HZU85FMs1Y=",
        "LI43bJyUlNTYBS00RdPXWlzohjUx1FnyXFdFslRUarNMB1Y=",
        "LI43bJyUdO0CJn9XxFI3ZN1+tiSEVVFT+JBE5dX/EmVTAVBU7CZNEFY=",
        "LI43bJyUdO0CJnFXxFI3ZN1+tiSEVVFTjDTelAH3zNd+VlTMM0zrVg==",
        "LI43bJyUdO0CJnFXxFI3ZN1+tiSEVVFTjDTelAHXZH5bOlpUyB1Mr1Y=",
        "LI43bJyUlNTYBS00RdPXWnxsNHHS3FlXRbJUVHQGQ8pW",
        "LI43bJyUlNTYBS00RdPXWnxsNHHyXFdFslRUZEdMX1Y=",
        "LI5H/ECMfgR99J/0n1RRVsHGZ3Hjdt9sAG74IAxN5GH0ZjRxADBx7lzyelVYx1XCuEBpVw==",
        "LI43NBRTVn9RgvbebPggzL3kRpBeDN8fUAdDclRUCFpeaVc=",
        "LI43NBRTVn9Rgl74EUIlDE1kZzRxKkUYCcxUVA0+XalX",
        "LI43NJRQxj9xg3andwISmFgMTeRGETAxlDgwRVJS1eFWP02kVlTXKl6FVw==",
        "LI5HDH1tByb/1PrUeldAXPhADF+QD1GCZsRUUAIe+sEQhXFUYU31UlS4m1jKVw==",
        "LI43NHRYSAJu+FG2wVhYVT+1dmcFEVCCXvhxMFpUE5Ze5Vc=",
        "LI5HzH3kAjTxlA5SaJQ1cVBS+FgMT9QX8VScSOjyZGRUVEm/X8NX",
        "LI43NBRTVn9Rgl44QQzfRCUMvWRnNDFUCkUYCcxUVEPNWTVX",
        "LI5HjH7tAjT/lAJSbEQMf21HAZA1cVxS+FgM33LmQXV2ZEeXyPlWPHZUuyhB1lc=",
        "LI5HDH3tAQbDFcNVWlAyXvhBjH7kwlVQlZQ1cVhS+FgMX9ZYMFVUGjla7lc=",
        "LI43NJRQVj9RgnanSQJumFC2wXx2dKoS05jU4VU04VZncYMeOkGEMdS/QIxeQIVR3pRVVEAdRAdX",
        "LI43NJRQVj9RgnanSQJumCAMneSFdWc0OZQO0FxclhBkITVWVDLJWz9X",
        "LI4R329FlGRYF1GV/xXQ13XMEnVR1lJZSWjCD8myLoXPoFcIClQSp528h5+fPGb5cOwdssGO/wREI76jH6lObKo9NKege2neQbVX",
        "LI5HDH/tQFBNNk30FDTylAZEUN740dxs+CAMX5AUbjQ5lA5wxcFcRRgJVkxyV1Sk9E7uVw==",
        "LI5HDH/tAib/1HrXeldAXPjAyN1+tuRGUFeC1nR6RdXhvO5Q4l74QRRFVVRc5UJPVw==",
        "LI5HjH7tAgYDFMNVWlAyXvhBjF5ADV9HJQxd1VXNVT9XgnYQTGJSONHdNL5GlGRNVH+DQ11X",
        "LI43NBRTVn9RghZ0GJA18ZcYdApN5GI0eXpFGAnMVFRyPEYjVw==",
        "LI5HDH/tAib/8HpXXNbVlALVzRToQZwLX9AUtORGWE1I4lIwUvhRFfycHvScDlxAjH5tRzxaxnpVWMdV6HdLfVc=",
        "LI5HzH3kAjT91HrXeldAVC10RXSd5EJ2tiSE1ZU18Zee1MFVFMXU4VU/FWj8XFcQEFQwmh500L/WztcwZlRfNk/dVw==",
        "LI5HDH7tAib9lAbSDFJ8RMzderbkhrX0V8RYDE3kQsNc8npVWMdVadNDc1c=",
        "LI5HDH/kQVwhTSBN9BQ08rAOHUBF08FaU0lMVgJS+FkM33525EVyduQGJnL+etXhvLJUVOOKQOFX",
        "LI5HDH/tAQYDFMNVWlAyHtaRTIKWEEgCVrUVU1LV2VU/V4J231AwlhBkIV00zFhUo7pCRVc=",
        "LI43NJRQxj9xA3anSVpu1GVXF5QOCHbM7mRVVB2qXltX",
        "LI5HDH/twbV0V0ZEzH3UcrbkhjUxlJ7U4awQZCFdNMxYVI5vRNNX",
        "LI43NDRsnNRdZJBIWm50pwLWrFp/VwJS+FGlV4JemMAIf+0BNHGXDsxOVXQLBgMUQ/VfVN9qWi9X",
        "LI43jJ8kxFVBuDHM3X6y5EZcW25kUABSMJYR1CjTwVhPV4JS+FHdXJhADH/kARTDNXkYQ8TjAhRDfFZTVEeTRq5X",
        "LI43NJRQxj9xMx46MQxft29IIFS31MFVPyXdNL6WUFQbk1qDVw==",
        "LI43bJyUdOQC9AU0cVdYlBCCXjjRXGxgFrUe1dlVPwURVgIWEGQhZTTMWFQMm0wVVw==",
        "LI5HDH9tByb/1HrXeldAXPjACN9+tiSEVdhXglL4kXHW/R9UlzBUKUBH4Vc=",
        "LI43NFRVnc1WZ03E1LAOncFWf1GClqxaU0m0TMNc8nogx1XRI0RtVw==",
        "LI5HDH7tACb5sAZVZDDcMTREVN34EEIlbLzU1uXdNL5GlGRNVLiuS5lX",
        "LI43NNTW11hc5EIBkDVxRPohbLyUVJaMEWQhZTTMWFQaDVq1Vw==",
        "LI43NJRQxj/VJH+XFUyLtfRX15cYZF2QjBFkITVWVCQ/WztX",
        "LI43NMQIfe0BJn+XFVJsxAh/bUcNkLX0V0xTOFnMTeRCGXBHdtb931WXMFRBR0KjVw==",
        "LI43NHRSbEgg1DdwxcEUXEM1bFyQf9WkdFfmXFhXVVR87ll7Vw==",
        "LI43NFTX11j8tHT+zJcVU1LTwRRc8OWl5b2VYENUuXBZe1c=",
        "LI43NFRVncFYU00EVObclxVTQNgZ0NVcJ1QrAURBVw==",
        "LI43bJyUdO0CJnFXxFI3ZN1yFlh0lkhUB31beVc=",
        "LI43NBRTVn9xg1a1HtLXFFpcZ2xIIBSVjBBkITVWVGCmR09X",
        "LI43bJyUlNTYBS00RdPXWlhaB9WgAERdQg29ZMfVVZbX3lYBHvpRlsEEBzR2f0V2VNLPQfJX",
        "LI43bJxUVWROkhK2b0gg1DdwxcEUXENV/wtd0FNlGNXfVFQKyURnVw==",
        "LI43NDRsnNSUZNSSIwy9JITVVdgDtkaVN14AWFTcsURnVw==",
        "LI43jJ8kxNVV2DU0e5cYAGXTwVpTSUw0TO9c8npSWMdVObhH01c=",
        "LI43NHRYSFpudKQe08GMEExa9jV4dlS0vkVnVw==",
        "LI43NFTW1wRYV3SiHnTQ3m1IIDQkDN105d00vjaUZE1UBmRHg1c=",
        "LI43bJyUlFSXRORGmpvQXGxIINQ3CHbM7kxkGFJUsulFYVc=",
        "LI43NDRsnNSURFQ2+VAW/NyXFVNS08FcRs9c8npSWMdV8vRBDVc=",
        "LI43bJyUlFSXRNR1tiSEVdUDNkM1dJZIVEkURjFX",
        "LI43bJyUdO0CJnlXxFI3ZF1Azd1EJWy8lLTkhlUWV2UIMHEWUAdDV9KdVMe6TcJX",
        "LI43bJyUdO0CJnFXxNJW3JwO0NyXFVNS08E0Rty1dhxsdEf4Tk1nNN5UVLoFQt5X",
        "LI43bJyUlNTYBS00RdPXWlzohjVxYkVSdphVVF+jQ29X",
        "LI43bJyUlNTYBS00RdPXWnxsNHHyXFdFslRUZEdMX1c=",
        "LI7P5CGWnl0UmFRTFIoYdIredhbSTlS8OkyxUA==",
        "LI7P5CaWgl1/c7xmlFXEa0fcgxoMj+RCfuYm1plQxO75ZGX4PoSYVVRFskubUA==",
        "LI4/DI00l9RWTgJimDg0zO3itTRXFlCcUrfhLID0zVdUT0JBYVA=",
        "LI7P5Caygs0/M74ahDHU1tLNWVNPTNQ2D3P4OQxfQuVV3/jIXcI9zN0ZmVBYJ1Q3/XZIUA==",
        "LI4/bIyUZCe5mMFZYlgEhOTmVX5SQ81dR5f3UpdIVEc7TmxQ",
        "LI43NBRTWWJZP4UQWmJkYPhQ3lc9QEVSWEVwYVQgoEW3UA==",
        "LI4/bIyUZCe5mMFn42JUDYwVVw0+VE+RQl1Q",
        "LI4/bIyUZCe5mPlnA2YUFZeYUuSMUE/sXMRbRZf7UoFIVKnRTZtQ",
        "LI4/bIyUZCexmM1HAhqMjuTCVVxOOE4UNj9z+FGFjFXyzlJYJ1Q91UkXUA==",
        "LI43NBRTWVNPTE44MvrJ7UaQ1t9UpZjhfHZ8PmRVVOmXQEJQ",
        "LI4/bIyUhDSHVHA19DUxlxh0EkJ1H1lU1OJDR1A=",
        "LI43NDQ0PGyMlNRYFKjSwVwFfCtyFviVUhfZWUx2zVBUuq5C4lA=",
        "LI4/bIyUZCW9kIzd8VkUQlxgNN6MYPg4zG6F9TV+xOKV9VIXUFRrQHUiUA==",
        "LI4/bIyUhDSXVFBZFELM4j3MbSd5V5eYwSRFdGknsZjNHHYMgfTOV1Rtrk+lUA==",
        "LI4/bIyUZCe5mMFn42JUDXSEZEeQzm0nsoJdZ0+C1hE4TnT+pP2VZFNUjBJwt1A=",
        "LI43NDxsjFSSZFSy+zjkFdzVEThOMlYRBZEEAGX0zVBU2PpMB1A=",
        "LI43NDxsjJSUVHFN9PjSwVliFNh+wh0MWeZtVMO1TMRQ",
        "LI4/bIyUZCe5mPln42JUDXRU9tWozTx2cP9VVIgtcJlQ",
        "LI4/bIyUhFSRRIQ0U7djjBURFLjBFBwcWd5tVFyFTgNQ",
        "LI43NDxsjFSVIlg0VLOPYIxhjPTcFGUMOHFMdt3UkcSsVEoHSPFQ",
        "LI4/bIyUhNTQTQQsREVSGVI5QFgBYSe5mOEEQQTFXWJHODR2VGV7TtVQ",
        "LI4/bIyUZDW/mOFn45qIjlQwZ2TUHERS3TXc+Mg0h+RCw04AJ1QijH1QUA==",
        "LI4/5D1sjJRUklhEVDKXEbV2HEx85kaa49XfmBDc1lRU21dLg1A=",
        "LI4/bIyUhNTQTQQsLBE4MvrJ7UKW09/4yO1GclZUJBR2zVA=",
        "LI4/bIyUhFSXf084TERouHYUGMhOVNIAd9VQ",
        "LI4/bIyUhNTQTQQsEN34OOSVclZUIDR3CVA=",
        "LI7P5CGWnl0UmFRTFIoYdIredhbSTlS8OkyxUQ==",
        "LI7P5CGWHnSAMdTXXQ9zmFC24UeClhEC1rUCcEUYYUyyVFQN4E8kUQ==",
        "LI7P5CaWAnSAOYQx1NZdf3OYUN/5OQxfQw1t1VUNWP9OYCdUE/J0qVE=",
        "LI7P5CGWnl3uRyBNtFScy201v9DhR4J23dS0gl1YZAV4PmSYVVQ7q0h5UQ==",
        "LI7P5CGWnl3uRyBNtFScy201v9DhR4J2EE5aYmRUkQK2Bdc1WlRWy03/UQ==",
        "LI43NBRTWVNPTDL6ye0ilgJEX3jm5jWymMFnMxoMXUOVBNddVHhCQgNR",
        "LI43NBRTWVNPTDL6ye0msgJEX3rmJrKYzX8FEASANFZUQaFBvVE=",
        "LI4/bIyUZCe5mM1n42YUFZeYUsSMns0PT4IWEQJiFAFhSJD9UpdIVImASrRR",
        "LI4/bIyUZDW/GHQ4VOYUVJzPXbabyN1w5kZYpfw9lGRTVB5BcrlR",
        "LI4/bIyUlJRkJ3FXSGAUEIKWDCTFwUx2HD50VA1ZVJpGQA9R",
        "LI4/bIyUZCe5mPln42JUDXRU9jP6yG1HdWYVI9Z4V16UAIfUNVpUlaVK71E=",
        "LI4/bIyUZCd5V5eY+VkUQlxgNNwUlJjBXCJXRe5Uk1FNz1E=",
        "LI43NDxsjFSSXITk5jUiF3IWWPJWGXDvNTKXHnAJPLJUVG2nQnBR",
        "LI4/bIyUhFSRRITk5jVyRNec4QRF5oBUVMniSSpR",
        "LI4/bIyUhOTGVVxO1HhMieRCF9AwYVQ+70M0UQ==",
        "LI4/bIyUZCe/mM1n42JUDXRU9jP6Ud713viQRHX0X1SOGXCdUQ==",
        "LI43NDxsjFSSZFS3d5CU6ME03H7SF3NQVFTDv0zcUQ==",
        "LI4/bIyUhFSRRIQU8JyY4WczmghfR1ff+FCW+WRFVBvKSgpR",
        "LI4/bIyUhFSWfxVwXGC0QtU2thBUd7B1sVE=",
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
    if (LANG == Language::Chinese)
        row_header_width(75);
    else
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
        if (LANG == Language::Chinese)
            z = " [" + std::to_string(ROW) + "]" + " " + zombies_zh[ROW];
        else
            z = " [" + std::to_string(ROW) + "]" + " " + zombies[ROW];
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
    // 25*6+10*2+10*(6+1)+30+5=275

    int w;  // 窗口宽度
    int h;  // 窗口高度
    int m;  // 控件边距
    int th; // 选项卡高度
    int tb; // 选项卡底部边框
    int iw; // 控件宽度 (1/4)
    int ih; // 控件高度 (1/6)

    if (LANG == Language::Chinese)
    {
        w = 450;
        h = 275;
        m = 10;
        th = 30;
        tb = 5;
        iw = 95;
        ih = 25;
    }
    else
    {
        w = 450 + 50 * 4;
        h = 275;
        m = 10;
        th = 30;
        tb = 5;
        iw = 95 + 50;
        ih = 25;
    }

    int x = m + m;           // 第一个控件的 x 坐标
    int y = m + th + tb + m; // 第一个控件的 y 坐标

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
    if (LANG == Language::Chinese)
        this->label("植物大战僵尸全版本辅助工具");
    else
        this->label("Plants vs. Zombies All Version Toolkit");

    if (LANG == Language::Chinese)
    {
        tabs = new Fl_Tabs(m, m, w - m * 2, h - m * 2);
        {
            group_resource = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "资源");
            {
                input_sun = new Fl_Value_Input(c(1) + 30, r(1), iw, ih, "");
                button_sun = new Fl_Button(c(2) + 30, r(1), iw - 30 - 10, ih, "阳光");
                input_money = new Fl_Value_Input(c(1) + 30, r(2), iw, ih, "10x");
                button_money = new Fl_Button(c(2) + 30, r(2), iw - 30 - 10, ih, "金钱");
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

            group_lineup = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "阵型");
            {
                check_lineup_mode = new Fl_Check_Button(c(1), r(1) + 5, iw + 15, ih, "快捷布阵模式");
                button_put_lily_pad = new Fl_Menu_Button(c(3) - 30, r(1) + 5, iw + 15, ih, "水路种睡莲");
                button_put_flower_pot = new Fl_Menu_Button(c(4) - 15, r(1) + 5, iw + 15, ih, "屋顶放花盆");
                button_array_design = new Fl_Button(c(1), r(3) - 20, iw + 10, ih, "网页布阵器");
                choice_lineup_scene = new Fl_Choice_(c(2) + 10 + 20, r(3) - 20, iw - 30, ih, "");
                choice_lineup_name[0] = new Fl_Choice_(c(3), r(3) - 20, iw * 2 + 10, ih, "");
                choice_lineup_name[1] = new Fl_Choice_(c(3), r(3) - 20, iw * 2 + 10, ih, "");
                choice_lineup_name[2] = new Fl_Choice_(c(3), r(3) - 20, iw * 2 + 10, ih, "");
                choice_lineup_name[3] = new Fl_Choice_(c(3), r(3) - 20, iw * 2 + 10, ih, "");
                choice_lineup_name[4] = new Fl_Choice_(c(3), r(3) - 20, iw * 2 + 10, ih, "");
                choice_lineup_name[5] = new Fl_Choice_(c(3), r(3) - 20, iw * 2 + 10, ih, "");
                button_get_lineup = new Fl_Button(c(1), r(4) - 15, iw, ih, "获取字符");
                button_copy_lineup = new Fl_Button(c(2), r(4) - 15, iw - 30, ih, "复制");
                button_paste_lineup = new Fl_Button(c(3) + 30, r(4) - 15, iw - 30, ih, "粘贴");
                button_set_lineup = new Fl_Button(c(4), r(4) - 15, iw, ih, "布置阵型");
                buffer_lineup_string = new Fl_Text_Buffer();
                editor_lineup_string = new Fl_Text_Editor(c(1), r(5) - 10, iw * 4 + 10 * 3, ih * 2 + 10 * 1 + 5, "");
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
                button_show_details = new Fl_Button(c(1), r(6), iw, ih, "显示详情");
                check_limit_count = new Fl_Check_Button(c(2), r(6), iw - 15, ih, "限制种数");
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
        game_status = new Fl_Box(230, 12, 190, 25, "");
        game_status_tooltip = new Fl_Box(430, 12, 10, 25, "");
    }
    else
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

            group_lineup = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "Lineup");
            {
                check_lineup_mode = new Fl_Check_Button(c(1), r(1) + 5, iw + 15, ih, "Quick Lineup Mode");
                button_put_lily_pad = new Fl_Menu_Button(c(3) - 55, r(1) + 5, iw + 20, ih, "Lily Pad On Pool");
                button_put_flower_pot = new Fl_Menu_Button(c(4) - 35, r(1) + 5, iw + 35, ih, "Flower Pot On Roof");
                button_array_design = new Fl_Button(c(1), r(3) - 20, iw + 40, ih, "Open Array Design Page");
                choice_lineup_scene = new Fl_Choice_(c(2) + 40 + 20 + 40, r(3) - 20, iw - 40 - 20, ih, "");
                choice_lineup_name[0] = new Fl_Choice_(c(3) + 40, r(3) - 20, iw * 2 + 10 - 40, ih, "");
                choice_lineup_name[1] = new Fl_Choice_(c(3) + 40, r(3) - 20, iw * 2 + 10 - 40, ih, "");
                choice_lineup_name[2] = new Fl_Choice_(c(3) + 40, r(3) - 20, iw * 2 + 10 - 40, ih, "");
                choice_lineup_name[3] = new Fl_Choice_(c(3) + 40, r(3) - 20, iw * 2 + 10 - 40, ih, "");
                choice_lineup_name[4] = new Fl_Choice_(c(3) + 40, r(3) - 20, iw * 2 + 10 - 40, ih, "");
                choice_lineup_name[5] = new Fl_Choice_(c(3) + 40, r(3) - 20, iw * 2 + 10 - 40, ih, "");
                button_get_lineup = new Fl_Button(c(1), r(4) - 15, iw, ih, "Get Lineup String");
                button_copy_lineup = new Fl_Button(c(2), r(4) - 15, iw - 60, ih, "Copy");
                button_paste_lineup = new Fl_Button(c(3) + 60 - 20, r(4) - 15, iw - 60, ih, "Paste");
                button_set_lineup = new Fl_Button(c(4) - 20, r(4) - 15, iw + 20, ih, "Apply Current Build");
                buffer_lineup_string = new Fl_Text_Buffer();
                editor_lineup_string = new Fl_Text_Editor(c(1), r(5) - 10, iw * 4 + 10 * 3, ih * 2 + 10 * 1 + 5, "");
            }
            group_lineup->end();

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
        game_status = new Fl_Box(390, 12, 230, 25, "");
        game_status_tooltip = new Fl_Box(630, 12, 10, 25, "");
    }
    this->end();

    if (LANG == Language::Chinese)
    {
        window_spawn = new Fl_Double_Window(860, 640, "出怪数量统计");
        {
            table_spawn = new SpawnTable(10, 10, 860 - 20, 640 - 20);
            button_update_details = new Fl_Button(10, 10, 75, 18 + 3, "↻");
        }
        window_spawn->end();
    }
    else
    {
        window_spawn = new Fl_Double_Window(860 + 120, 640, "Spawning Counting");
        {
            table_spawn = new SpawnTable(10, 10, 860 + 120 - 20, 640 - 20);
            button_update_details = new Fl_Button(10, 10, 75 + 120, 18 + 3, "↻");
        }
        window_spawn->end();
    }

    // 默认值

    group_resource->selection_color(FL_DARK2);
    group_battle->selection_color(FL_DARK2);
    group_lineup->selection_color(FL_DARK2);
    group_spawn->selection_color(FL_DARK2);
    group_others->selection_color(FL_DARK2);
    tabs->selection_color(FL_WHITE);

    input_sun->value(8000);
    input_sun->bounds(0, 9990);

    input_money->value(80000);
    input_money->bounds(0, 99999);

    input_wisdom_tree->value(1000);
    input_wisdom_tree->bounds(0, 99999);

    if (LANG == Language::Chinese)
    {
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
    }
    else
    {
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
    }
    choice_slot->value(0);

    for (size_t i = 0; i < 48; i++)
    {
        std::string p;
        if (LANG == Language::Chinese)
            p = "[" + std::to_string(i) + "]" + " " + plants_zh[i];
        else
            p = "[" + std::to_string(i) + "]" + " " + plants[i];
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

    if (LANG == Language::Chinese)
    {
        choice_row->add("所有行");
        choice_row->add("第 1 行");
        choice_row->add("第 2 行");
        choice_row->add("第 3 行");
        choice_row->add("第 4 行");
        choice_row->add("第 5 行");
        choice_row->add("第 6 行");
    }
    else
    {
        choice_row->add("All Rows");
        choice_row->add("1st Row");
        choice_row->add("2nd Row");
        choice_row->add("3rd Row");
        choice_row->add("4th Row");
        choice_row->add("5th Row");
        choice_row->add("6th Row");
    }
    choice_row->value(1);

    if (LANG == Language::Chinese)
    {
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
    }
    else
    {
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
    }
    choice_col->value(1);

    for (size_t i = 0; i < 48; i++)
    {
        std::string p;
        if (LANG == Language::Chinese)
            p = "[" + std::to_string(i) + "]" + " " + plants_zh[i];
        else
            p = "[" + std::to_string(i) + "]" + " " + plants[i];
        choice_plant->add(p.c_str());
    }
    choice_plant->value(0);

    for (size_t i = 0; i < 33; i++)
    {
        std::string z;
        if (LANG == Language::Chinese)
            z = "[" + std::to_string(i) + "]" + " " + zombies_zh[i];
        else
            z = "[" + std::to_string(i) + "]" + " " + zombies[i];
        choice_zombie->add(z.c_str());
    }
    choice_zombie->value(0);

    if (LANG == Language::Chinese)
    {
        choice_item->add("植物");
        choice_item->add("僵尸");
        choice_item->add("推车");
        choice_item->add("墓碑");
        choice_item->add("梯子");
        choice_item->add("钉耙");
    }
    else
    {
        choice_item->add("Plants");
        choice_item->add("Zombies");
        choice_item->add("Lawn Mowers");
        choice_item->add("Graves");
        choice_item->add("Ladders");
        choice_item->add("Rakes");
    }
    choice_item->value(2);

    for (size_t i = 0; i < 9; i++)
    {
        std::string label = std::to_string(lily_pad_col_lower[i]) //
                            + " -> " + std::to_string(lily_pad_col_upper[i]);
        button_put_lily_pad->add(label.c_str(), 0, cb_put_lily_pad, this);
    }

    for (size_t i = 0; i < 9; i++)
    {
        std::string label = std::to_string(flower_pot_col_lower[i]) //
                            + " -> " + std::to_string(flower_pot_col_upper[i]);
        button_put_flower_pot->add(label.c_str(), 0, cb_put_flower_pot, this);
    }

    if (LANG == Language::Chinese)
    {
        choice_lineup_scene->add("白天");
        choice_lineup_scene->add("黑夜");
        choice_lineup_scene->add("泳池");
        choice_lineup_scene->add("雾夜");
        choice_lineup_scene->add("屋顶");
        choice_lineup_scene->add("月夜");
    }
    else
    {
        choice_lineup_scene->add("Day");
        choice_lineup_scene->add("Night");
        choice_lineup_scene->add("Pool");
        choice_lineup_scene->add("Fog");
        choice_lineup_scene->add("Roof");
        choice_lineup_scene->add("Moon");
    }
    choice_lineup_scene->value(2);

    choice_lineup_name[0]->hide();
    choice_lineup_name[1]->hide();
    // choice_lineup_name[2]->hide();
    choice_lineup_name[3]->hide();
    choice_lineup_name[4]->hide();
    choice_lineup_name[5]->hide();

    lineup_count[0] = 0;
    lineup_count[1] = 0;
    lineup_count[2] = 0;
    lineup_count[3] = 0;
    lineup_count[4] = 0;
    lineup_count[5] = 0;
    for (size_t i = 0; i < 324; i++) // TODO 阵型数量
    {
        std::string name = std::string(lineup_names[i]);
        char *scene[] = {"[DE]", "[NE]", "[PE]", "[FE]", "[RE]", "[ME]"};
        for (size_t j = 0; j < 6; j++)
        {
            if (name.find(scene[j]) != std::string::npos)
            {
                choice_lineup_name[j]->add(lineup_names[i]);
                lineup_count[j]++;
                break;
            }
        }
    }
    choice_lineup_name[0]->value(15); // DE双冰六炮
    choice_lineup_name[1]->value(28); // NE快六炮
    choice_lineup_name[2]->value(57); // PE经典八炮
    choice_lineup_name[3]->value(33); // FE经典八炮
    choice_lineup_name[4]->value(17); // RE天台十炮
    choice_lineup_name[5]->value(15); // ME月夜十炮

    editor_lineup_string->buffer(buffer_lineup_string);
    editor_lineup_string->wrap_mode(Fl_Text_Editor::WRAP_AT_BOUNDS, 0);
    editor_lineup_string->deactivate(); // 不可编辑

#ifdef _DEBUG
    size_t lineup_length_total = 0;
    for (size_t i = 0; i < 324; i++)
        lineup_length_total += std::string(lineup_strings[i]).size();
    std::cout << "lineup string length avg: " << (lineup_length_total / 324) << std::endl;
#endif

    for (size_t i = 0; i < 20; i++)
        if (LANG == Language::Chinese)
            check_zombie[i]->label(zombies_zh[spawn_type[i]]);
        else
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
                    std::string adventure_level;
                    if (LANG == Language::Chinese)
                        adventure_level = std::string() + "[0]" + " " + std::string(modes_zh[0]) //
                                          + " " + std::to_string(j) + "-" + std::to_string(k);
                    else
                        adventure_level = std::string() + "[0]" + " " + std::string(modes[0]) //
                                          + " " + std::to_string(j) + "-" + std::to_string(k);
                    choice_mode->add(adventure_level.c_str());
                }
            }
        }
        else
        {
            std::string mode;
            if (LANG == Language::Chinese)
                mode = std::string() + "[" + std::to_string(i) + "]" + " " + std::string(modes_zh[i]);
            else
                mode = std::string() + "[" + std::to_string(i) + "]" + " " + std::string(modes[i]);
            choice_mode->add(mode.c_str());
        }
    }
    // 默认无尽模式
    choice_mode->value(50 + 13 - 1);

    if (LANG == Language::Chinese)
    {
        choice_debug->add("关闭");
        choice_debug->add("出怪");
        choice_debug->add("音乐");
        choice_debug->add("内存");
        choice_debug->add("碰撞");
    }
    else
    {
        choice_debug->add("Off");
        choice_debug->add("Spawning");
        choice_debug->add("Music");
        choice_debug->add("Memory");
        choice_debug->add("Collision");
    }
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

    check_lineup_mode->callback(cb_lineup_mode, this);
    button_array_design->callback(cb_array_design, this);
    choice_lineup_scene->callback(cb_switch_lineup_scene, this);
    choice_lineup_name[0]->callback(cb_show_lineup_string, this);
    choice_lineup_name[1]->callback(cb_show_lineup_string, this);
    choice_lineup_name[2]->callback(cb_show_lineup_string, this);
    choice_lineup_name[3]->callback(cb_show_lineup_string, this);
    choice_lineup_name[4]->callback(cb_show_lineup_string, this);
    choice_lineup_name[5]->callback(cb_show_lineup_string, this);
    button_copy_lineup->callback(cb_copy_lineup, this);
    button_paste_lineup->callback(cb_paste_lineup, this);
    button_get_lineup->callback(cb_get_lineup, this);
    button_set_lineup->callback(cb_set_lineup, this);

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
    static Fl_Font ls_font = (FL_FREE_FONT + 2);
    Fl::set_font(pt_font, "Microsoft YaHei");
    Fl::set_font(ls_font, "Courier New");

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
            for (int i = 0; i < group_lineup->children(); i++)
                group_lineup->child(i)->labelfont(pt_font);
            choice_lineup_scene->textfont(pt_font);
            choice_lineup_name[0]->textfont(pt_font);
            choice_lineup_name[1]->textfont(pt_font);
            choice_lineup_name[2]->textfont(pt_font);
            choice_lineup_name[3]->textfont(pt_font);
            choice_lineup_name[4]->textfont(pt_font);
            choice_lineup_name[5]->textfont(pt_font);
            editor_lineup_string->textfont(ls_font); // 阵型字符串特殊字体
            editor_lineup_string->textsize(16);
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

    // 显示默认阵型的字符串
    choice_lineup_scene->do_callback();

    // 工作类

    pvz = new PvZ();
    pvz->callback(cb_find_result, this);
    // pvz->FindPvZ(); // 在 main() 里调用

    pak = new PAK();

    // this->show(); // 在 main() 里带参调用
}

Window::~Window()
{
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

std::string Window::convert_lineup(const std::string &str)
{
    auto split = [](const std::string &str, char seperator) -> std::vector<std::string> {
        std::vector<std::string> result;
        std::string::size_type prev = 0, pos = 0;
        while ((pos = str.find(seperator, pos)) != std::string::npos)
        {
            std::string sub_string(str.substr(prev, pos - prev));
            result.push_back(sub_string);
            prev = ++pos;
        }
        result.push_back(str.substr(prev, pos - prev));
        return result;
    };

    auto hex2dec = [](const std::string &str) -> long {
        char *ptr;
        long num;
        num = strtol(str.c_str(), &ptr, 16);
        return num;
    };

    const bool may_sleep[] = {false, false, false, false, false, false, false, false,
                              true, true, true, false, true, true, true, true,
                              false, false, false, false, false, false, false, false,
                              true, false, false, false, false, false, false, true,
                              false, false, false, false, false, false, false, false,
                              false, false, true, false, false, false, false, false};

    uint16_t items[6 * 9] = {0};
    uint8_t rake_row = 0, scene = 2;

    std::vector<std::string> str_list = split(str, ',');
    size_t count = str_list.size() - 1;

    std::string str_scene = str_list[0];
    if (str_scene == "0") // pool
        scene = 2;
    else if (str_scene == "1") // fog
        scene = 3;
    else if (str_scene == "2") // day
        scene = 0;
    else if (str_scene == "3") // night
        scene = 1;
    else if (str_scene == "4") // roof
        scene = 4;
    else if (str_scene == "5") // moon
        scene = 5;

    uint16_t plant[6 * 9] = {0};
    uint16_t plant_im[6 * 9] = {0};
    uint16_t plant_awake[6 * 9] = {0};
    uint16_t base[6 * 9] = {0};
    uint16_t base_im[6 * 9] = {0};
    uint16_t pumpkin[6 * 9] = {0};
    uint16_t pumpkin_im[6 * 9] = {0};
    uint16_t coffee[6 * 9] = {0};
    uint16_t coffee_im[6 * 9] = {0};
    uint16_t ladder[6 * 9] = {0};

    for (size_t i = 0; i < count; i++)
    {
        std::vector<std::string> item_str = split(str_list[i + 1], ' ');
        int item_type = hex2dec(item_str[0]);
        int item_row = atoi(item_str[1].c_str()) - 1;
        int item_col = atoi(item_str[2].c_str()) - 1;
        int item_state_row = atoi(item_str[3].c_str());
        int item_state_col = atoi(item_str[4].c_str());
        bool item_imitater = atoi(item_str[5].c_str()) != 0;

        if (item_type < 0 || item_type > 0x32)
            continue;

        if (item_type == 16 || item_type == 33 || item_type == 50)
        {
            if (item_type == 16) // 睡莲
            {
                base[item_row * 9 + item_col] = 1;
                base_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
            }
            else if (item_type == 33) // 花盆
            {
                base[item_row * 9 + item_col] = 2;
                base_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
            }
            else // 墓碑 0x32
            {
                base[item_row * 9 + item_col] = 3;
                base_im[item_row * 9 + item_col] = 0;
            }
        }
        else if (item_type == 30) // 南瓜
        {
            pumpkin[item_row * 9 + item_col] = 1;
            pumpkin_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 35) // 咖啡
        {
            coffee[item_row * 9 + item_col] = 1;
            coffee_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 48) // 梯子 0x30
        {
            ladder[item_row * 9 + item_col] = 1;
        }
        else if (item_type == 49) // 钉耙 0x31
        {
            rake_row = item_row + 1;
        }
        else // 主要植物
        {
            plant[item_row * 9 + item_col] = item_type + 1;
            plant_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
            plant_awake[item_row * 9 + item_col] = ((scene == 0 || scene == 2 || scene == 4) && may_sleep[item_type] && item_state_row == 0) ? 0 : 1;
        }
    }

    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            uint16_t item = 0;
            item += 0b1111110000000000 & (plant[r * 9 + c] << 10);
            item += 0b0000001000000000 & (plant_im[r * 9 + c] << 9);
            item += 0b0000000100000000 & (plant_awake[r * 9 + c] << 8);
            item += 0b0000000011000000 & (base[r * 9 + c] << 6);
            item += 0b0000000000100000 & (base_im[r * 9 + c] << 5);
            item += 0b0000000000010000 & (pumpkin[r * 9 + c] << 4);
            item += 0b0000000000001000 & (pumpkin_im[r * 9 + c] << 3);
            item += 0b0000000000000100 & (coffee[r * 9 + c] << 2);
            item += 0b0000000000000010 & (coffee_im[r * 9 + c] << 1);
            item += 0b0000000000000001 & (ladder[r * 9 + c] << 0);
            items[r * 9 + c] = item;
        }
    }

    // #ifdef _DEBUG
    //     std::cout << std::endl;
    //     for (int r = 0; r < 6; r++)
    //     {
    //         for (int c = 0; c < 9; c++)
    //             std::cout << std::bitset<16>(items[r * 9 + c]) << " ";
    //         std::cout << std::endl;
    //     }
    //     std::cout << std::bitset<8>((rake_row << 4) | (scene & 0b00001111));
    //     std::cout << std::endl;
    // #endif

    unsigned long size = 121; // compressBound(6*9*2)
    unsigned char lineup_bin[128] = {0};
    unsigned long cut_size = ((scene == 2 || scene == 3) ? 6 : 5) * 9 * sizeof(uint16_t);
    compress2(lineup_bin, &size, (unsigned char *)items, cut_size, Z_BEST_COMPRESSION);
    lineup_bin[size - 1 + 1] = (rake_row << 4) | (scene & 0b00001111);

    for (size_t i = 0; i < size + 1; i++)
        lineup_bin[i] = lineup_bin[i] ^ (unsigned char)0x54;

    DWORD len = 256;
    char lineup_str[256] = {0};
    CryptBinaryToStringA(lineup_bin, size + 1, CRYPT_STRING_BASE64, lineup_str, &len);

    std::string lineup(lineup_str);
    lineup.erase(std::remove(lineup.begin(), lineup.end(), '\r'), lineup.end());
    lineup.erase(std::remove(lineup.begin(), lineup.end(), '\n'), lineup.end());
    // std::cout << lineup << " " << lineup.size() << std::endl;

    return lineup;
}

void Window::cb_find_result(void *w, int result)
{
    ((Window *)w)->cb_find_result(result);
}

void Window::cb_find_result(int result)
{
    if (LANG == Language::Chinese)
    {
        switch (result)
        {
        case PVZ_1_0_0_1051_EN:
            game_status->label("1.0.0.1051 英文原始版");
            break;
        case PVZ_1_2_0_1065_EN:
            game_status->label("1.2.0.1065 英文修复版");
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
        case PVZ_1_1_0_1056_ZH:
            game_status->label("1.1.0.1056 粘度汗化版");
            {
                int ret = MessageBoxW(GetActiveWindow(),                                //
                                      L"这个版本的游戏存在严重的问题, 随时可能会崩溃. " //
                                      L"建议更换使用其他正常的版本, 现在去下载吗?",     //
                                      L"警告",                                          //
                                      MB_OKCANCEL | MB_ICONWARNING);
                if (ret == IDOK)
                    ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/download/", //
                                  nullptr, nullptr, SW_SHOWNORMAL);
            }
            break;
        case PVZ_1_1_0_1056_JA:
            game_status->label("1.1.0.1056 日文年度版");
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
    }
    else
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
                    ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/download/", //
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
    }

    if (result != PVZ_NOT_FOUND && result != PVZ_OPEN_ERROR && result != PVZ_UNSUPPORTED)
    {
        this->keep_selected_feature(); // 重新找到游戏时应用所有已选功能
        if (LANG == Language::Chinese)
        {
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
    else
    {
        game_status_tooltip->label("");
        game_status_tooltip->tooltip(nullptr);
    }

    game_status->redraw();
    game_status_tooltip->redraw();
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
        check_lineup_mode, // 这个放在最后
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

void Window::cb_lineup_mode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_lineup_mode();
}

void Window::cb_lineup_mode()
{
    std::vector<Fl_Check_Button *> check_buttons = {
        check_auto_collect,
        check_free_planting,
        check_plant_invincible,
        check_reload_instantly,
        check_stop_spawning,
        check_no_fog,
    };

    if (check_lineup_mode->value())
    {
        // 勾选时开启所有功能, 然后按钮组恢复原状态
        for (size_t i = 0; i < check_buttons.size(); i++)
        {
            check_buttons[i]->deactivate();
            int ori_val = check_buttons[i]->value();
            check_buttons[i]->value(1);
            check_buttons[i]->do_callback();
            check_buttons[i]->value(ori_val);
        }
    }
    else
    {
        // 取消时应用按钮组已勾选状态
        for (size_t i = 0; i < check_buttons.size(); i++)
        {
            check_buttons[i]->activate();
            check_buttons[i]->do_callback();
        }
    }
}

void Window::cb_put_lily_pad(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_lily_pad();
}

void Window::cb_put_lily_pad()
{
    int i = button_put_lily_pad->value();
    int from_col = lily_pad_col_lower[i];
    int to_col = lily_pad_col_upper[i];
    pvz->LilyPadOnPool(from_col, to_col);
}

void Window::cb_put_flower_pot(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_flower_pot();
}

void Window::cb_put_flower_pot()
{
    int i = button_put_flower_pot->value();
    int from_col = flower_pot_col_lower[i];
    int to_col = flower_pot_col_upper[i];
    pvz->FlowerPotOnRoof(from_col, to_col);
}

void Window::cb_array_design(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_array_design();
}

void Window::cb_array_design()
{
    ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/lineup/", nullptr, nullptr, SW_SHOWNORMAL);
}

void Window::cb_switch_lineup_scene(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_switch_lineup_scene();
}

void Window::cb_switch_lineup_scene()
{
    for (size_t i = 0; i < 6; i++)
    {
        if (i == choice_lineup_scene->value())
            choice_lineup_name[i]->show();
        else
            choice_lineup_name[i]->hide();
    }
    cb_show_lineup_string();
}

void Window::cb_show_lineup_string(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_show_lineup_string();
}

void Window::cb_show_lineup_string()
{
    int index = 0;
    for (int i = 0; i < choice_lineup_scene->value(); i++)
        index += lineup_count[i];
    index += choice_lineup_name[choice_lineup_scene->value()]->value();
#ifdef _DEBUG
    std::cout << index << " " << lineup_names[index] << std::endl;
#endif
    buffer_lineup_string->text(lineup_strings[index]);
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

    // 网页布阵器格式转成新格式
    std::string str = buffer_lineup_string->text();
    std::regex reg("[0-5](,[a-fA-F0-9]{1,2} [1-6] [1-9] [0-2] [0-4] [0-1]){0,}");
    if (std::regex_match(str, reg))
    {
        std::string new_str = convert_lineup(str);
        buffer_lineup_string->text(new_str.c_str());
    }
}

void Window::cb_get_lineup(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_get_lineup();
}

void Window::cb_get_lineup()
{
    std::string str = pvz->GetLineup();
    buffer_lineup_string->text(str.c_str());
}

void Window::cb_set_lineup(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_set_lineup();
}

void Window::cb_set_lineup()
{
    std::string str = buffer_lineup_string->text();

    // Base64Url 转标准 Base64
    std::replace(str.begin(), str.end(), '-', '+');
    std::replace(str.begin(), str.end(), '_', '/');
    switch (str.size() % 4)
    {
    case 0:
        break;
    case 1:
        return;
    case 2:
        str += "==";
        break;
    case 3:
        str += "=";
        break;
    }

    pvz->SetLineup(str);
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
        if (LANG == Language::Chinese)
            button_show_details->copy_label("隐藏详情");
        else
            button_show_details->copy_label("Hide Details");
        window_spawn->show();
        cb_update_details();
    }
    else
    {
        if (LANG == Language::Chinese)
            button_show_details->copy_label("显示详情");
        else
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
    if (LANG == Language::Chinese)
        window_spawn->size(860, 640 - deleted_rows * 18);
    else
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

    // 2000/XP 系统下才会使用 `安装目录/userdata` 做存档位置
    // 需要找到游戏才能定位到游戏安装目录
    if (dwMajorVersion < 6 && !pvz->path.empty())
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
    if (LANG == Language::Chinese)
        bi.lpszTitle = L"选择要打包的文件夹";
    else
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
    HANDLE hThread = CreateThread(nullptr, 0, cb_unpack_thread, this, 0, nullptr);
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

    if (LANG == Language::Chinese)
    {
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
    }
    else
    {
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
    HANDLE hThread = CreateThread(nullptr, 0, cb_pack_thread, this, 0, nullptr);
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

    if (LANG == Language::Chinese)
    {
        if (ret == PACK_SUCCESS)
        {
            std::wstring text = L"打包完成, 文件位于: \n" + dst_file + L"\n\n" //
                                + L"将名称修改为 \"main.pak\" 并替换同名原文件 (事先备份).";
            MessageBoxW(GetActiveWindow(), text.c_str(), L"提示", MB_OK | MB_ICONINFORMATION);
        }
        else
        {
            std::wstring text = L"打包出错.";
            MessageBoxW(GetActiveWindow(), text.c_str(), L"提示", MB_OK | MB_ICONERROR);
        }
    }
    else
    {
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
    ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/download/", nullptr, nullptr, SW_SHOWNORMAL);
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
    if (LANG == Language::Chinese)
    {
        std::wstring text = std::wstring()                                                  //
                            + L"PvZ Toolkit 是一个适用于植物大战僵尸一代 PC 版的修改器\n"   //
                            + L"\n"                                                         //
                            + L"支持的游戏版本: \n"                                         //
                            + L"✓ 英文原始版 1.0.0.1051 (en)\n"                             //
                            + L"✓ 英文修复版 1.2.0.1065 (en)\n"                             //
                            + L"✓ 英文年度版 1.2.0.1073 GOTY (en)\n"                        //
                            + L"✓ Steam 英文年度版 1.2.0.1096 GOTY (en)\n"                  //
                            + L"✓ Origin 多国语言年度版 1.2.0.1093 GOTY (de, es, fr, it)\n" //
                            + L"✓ 粘度汗化版 1.1.0.1056 GOTY (zh)\n"                        //
                            + L"✓ 日文年度版 1.1.0.1056 GOTY (ja)\n"                        //
                            + L"✓ 年度汉化加强版 1.1.0.1056 GOTY 2012.06 (zh)\n"            //
                            + L"✓ 年度汉化加强版 1.1.0.1056 GOTY 2012.07 (zh)\n"            //
                            + L"\n"                                                         //
                            + L"版本号: 1.4.0.10400\n"                                      //
                            + L"构建日期: 2020/09/25\n"                                     //
                            + L"工具链: MSVC 2017 / FLTK 1.4.x / zlib 1.2.11\n"             //
                            + L"版权所有: © 2020 lmintlcx\n"                                //
                            + L"鸣谢: a418569882 kmtohoem\n";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"关于 PvZ Toolkit", MB_OK);
    }
    else
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
                            + L"Version: 1.4.0.10400\n"                                                    //
                            + L"Build Date: 2020/09/25\n"                                                  //
                            + L"Toolchain: MSVC 2017 / FLTK 1.4.x / zlib 1.2.11\n"                         //
                            + L"Copyright: © 2020 lmintlcx\n"                                              //
                            + L"Credit: a418569882 kmtohoem\n";
        MessageBoxW(GetActiveWindow(), text.c_str(), L"About PvZ Toolkit", MB_OK);
    }
}

void Window::cb_on_hide_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_on_hide_details();
}

void Window::cb_on_hide_details()
{
    if (LANG == Language::Chinese)
        button_show_details->copy_label("显示详情");
    else
        button_show_details->copy_label("Show Details");
    window_spawn->hide();
}

} // namespace Pt
