
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
        "[DE].柱子五炮",
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
        "[DE].中开十四炮",
        "[DE].雪花十四炮",
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
        "[NE].点赞三炮",
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
        "[NE].鬼位五炮",
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
        "[NE].十九炮",
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
        "[PE].葬花吟",
        "[PE].神之四炮",
        "[PE].双核底线四炮",
        "[PE].经典四炮",
        "[PE].心四炮",
        "[PE].火焰四炮",
        "[PE].底线四炮",
        "[PE].传统四炮",
        "[PE].半场无植物五炮",
        "[PE].散炸五炮",
        "[PE].心五炮",
        "[PE].陆路无植物六炮",
        "[PE].水路无植物六炮",
        "[PE].禅房花木深",
        "[PE].青苔六炮",
        "[PE].神之六炮",
        "[PE].玉米六炮",
        "[PE].空炸六炮",
        "[PE].超后置六炮",
        "[PE].方六炮",
        "[PE].蝶韵",
        "[PE].一勺汤圆",
        "[PE].间隔无植物七炮",
        "[PE].玉兔茕茕",
        "[PE].无保护八炮",
        "[PE].树八炮",
        "[PE].全对称树八炮",
        "[PE].矩形八炮",
        "[PE].无套神之八炮",
        "[PE].灯台八炮",
        "[PE].神之八炮",
        "[PE].阴阳八炮",
        "[PE].浮萍八炮",
        "[PE].后置八炮",
        "[PE].饲养海豚",
        "[PE].玉米八炮",
        "[PE].经典八炮",
        "[PE].花海八炮",
        "[PE].C2八炮",
        "[PE].冰心灯八炮",
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
        "[PE].方块十炮",
        "[PE].六边形十炮",
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
        "[PE].炮环十二花",
        "[PE].冰箱灯",
        "[PE].对称十六炮",
        "[PE].神之十六炮",
        "[PE].裸奔十六炮",
        "[PE].双冰十六炮",
        "[PE].超前置十六炮",
        "[PE].火焰十六炮",
        "[PE].经典十六炮",
        "[PE].冰魄十八炮",
        "[PE].真·十八炮",
        "[PE].纯十八炮",
        "[PE].尾炸十八炮",
        "[PE].经典十八炮",
        "[PE].日花二十炮",
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
        "[FE].三角板六炮",
        "[FE].玲珑六炮",
        "[FE].烈焰八炮",
        "[FE].无保护八炮",
        "[FE].神之八炮",
        "[FE].经典八炮",
        "[FE].七夕灯",
        "[FE].斜方十炮",
        "[FE].河洛十炮",
        "[FE].纯十二炮",
        "[FE].水路无植物十二炮",
        "[FE].神之十二炮",
        "[FE].曲径通幽处",
        "[FE].某十四炮",
        "[FE].礼物盒十四炮",
        "[FE].弦十四炮",
        "[FE].奇门九劫",
        "[FE].半场十四炮",
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
        "[RE].十一炮",
        "[RE].花灯十二炮",
        "[RE].椭盘十二炮",
        "[RE].螺旋十二炮",
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
        "[ME].十九炮",
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
        "LI5HzH3tAibxsALS11gEdBRxRVTCikaVVA==",
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
        "LI43DJ3kxrV0V1dIZ2Q03oxUdX5s3NLl3FRU85BZ/1Q=",
        "LI43DJ3kxrV0V1dMF1TWW0dv3NJNTDhkgIx03dVVVPcZWWpU",
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
        "LI43NJRQxj8FrVZ/cTMe+jBs3HbmAiZ/zpwYAEVUAEZd6VU=",
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
        "LI5HDH3kxrV0V0ZEzH3tQnB25EJ6lnRdAndkR9vOwcY8slRUO6dY0lU=",
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
        "LI43bJyUlNTYBS0kRdXBVn9d/RVBVVSx51uSVQ==",
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
        "LI43NDQ0xAidlHRUkGR07cLVFSRiBDh50Etlh7X0VxfUSczI2UTd5BXcFCAdmhC8NpRkTVSYK0VtVg==",
        "LI43NJRQxj9xMx46MQxft29IIFS31MEU7ELvXPJ6GFRU5c9EnVY=",
        "LI43bJyUdOQCNHmXAlJSUlNSRFTeHPpBzF1GRSRU3W2YIAy95GZUXBWGWnRFTzBFIAlcReydNFRUUexBjFY=",
        "LI43NMQIfe3BldJVXRz6wchdQA9ft29IIFS3VM/U4Tx2f1eCtoaR1DVmVFO7RlZW",
        "LI4B3+VFVGRcVk2VwgkG7HrRMVKcMsXnnLFfLe1XXAVUQSkZAEBjkTknx3PF/yeN0r2KO7wJtdcuKlXzIUWJVg==",
        "LI5HDH7tAib9sAbSDFJ8RMzderYkhFXYVwJSjFD4EUcNXUWVgHHUNWZUGEZD+lY=",
        "LI43bJyUdO0CJvGUAlIJUlyURCUMvWSHNTHU2ZSS1MFVP8URVuJS+NHc1CBd+EGMfvTfOFr+XFQj00OhVg==",
        "LI5HjH7kAjT/1HrXeldAXJhQ3vhBDH3kwTV5EJC19FdMU/hY5F0MX9Ycdg91dszuUGQYUlR6YUggVg==",
        "LI5H5MUIf+0GJn+XFVJ8RNTc+BDcbEgg1LfU4XScFEJUVEgKWSFW",
        "LI43NMQIXtZY5VgkdOQCNPKUAtLhZOqXFVNkWoxO5GI0eebclJLUzVViRAHGP3EzHjoxDN2Ec+1GXONmSNClVZiCQgxW",
        "LI43NMQIf23H1RU08ZQeUlxsnFRGj172UYLWUEg4SFpuZNQklJ7U4UQRWj8VKNXZZGpcHJrAiH7UtLtRFlIdCdBoVO/lR89W",
        "LI43NHRYSFpulCWUHnQI330W0GVYVIQCWTFW",
        "LI43bJyUdO0CJnFXxNJWGEV21NRZ7kr0nBid+Zx2VPkWX2NW",
        "LI43NDRsnFSVXGQHJvmwDtLNZPqXFVNS08EUXPD1dn9JOJT2Ylp/Jb1W1sE0J7V+VIfTRSVW",
        "LI43NDRsnFSVXOQGJvmwDtLBZPqXHlNP09daWBQmcXpFGAlYTHJXVJx9RINW",
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
        "LI43NJRWgma4UYdTdQjTwVo/SVpuZJTlWfJc8noYVFTOUUTVVg==",
        "LI435DUMncRd0H9NOEx0tHRX17AOneF0TlZIAm6MbEggNFTGf7U2dGpEd1Xc2uEcdlP1TF5UvN9bgVY=",
        "LI43NJRQxj/VJH+XFUyLtfRX15cYZF2QjBFkITVWVCQ/WztW",
        "LI43NMSIfu0GJnnXWVdAXDjBCH9tByZxBDB5EJA18ZcYdOIlbLxUAbfkQpxTpkR2WFPFZO5MQFRU/iFHVFY=",
        "LI43bJyUdO0GJnFXxFI3ZH3tAiZ5xlwFVPiTUg3TsAL07Rx2VHKpWPlW",
        "LI43NMQIf+3BtXRXRsTI3X62JIRV2FcyUvgRR41eR5WAkdQ1ZlRFJEZNVg==",
        "LI43NMQIf+0GJn+XFVJsVKYzdt9QmCBsvJRUllVnV4LWELSo+RSN4QQJZwUZNVTN2HZWVIR3QNJW",
        "LI5HvMEIf41/jZ+EnyTEVVhQZBBIWm4UpB5TT9PBjBFQ3GRTVPknTcFW",
        "LI43NMSIXtZYU020FCb5sBgwRdPXWjRI5GE0MpQOYMXBREUYCVhMcldUcSdDG1Y=",
        "LI5HDH1d0lhTTUxMAlZl15QeneEU3HC25EZeW25k1CTUWfJc8npVWMdVgpZLTVY=",
        "LI5HDJ8kxNVV2PUUNHmXGGQreRiQlZo18ZcVU9LUwVUEZVNPIEUYCVZMcldUCDpHFVY=",
        "LI43bJyUdO0CJnlXxNJVdCtxRPrRpUlabmRsjFR1xJJx1v3fVZcwVATYR2VW",
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
        "LI43NHRYSFpuFKQeU08IdlhTxWRaRVRy/lgBVg==",
        "LI43NJReWhZlQGxIIDQkDL00V/ZFKGRfelIC68aVUg1L/m1U3CdZblY=",
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
        "LI43bJyUlNTYdbAefFDfbEggNCQMvTRX0H8VODh2zO5MZBhSVD8vTLlW",
        "LI43bJyUlNTYTUwC1j1PdGhcsmVsSCA0JOTVFnRPz1zyelJYx1XkQEHRVg==",
        "LI43NFTW1xToRhiWVN7clxVTXOLV52QQTNxkU1Rj1Ef5Vg==",
        "LI43NJRUU4Vk15cVUwA4133W/V9HVFTlfUVdVg==",
        "LI43NHRYSFpu9LRUTxhF0tcU0ZzMVQdQVImORX1W",
        "LI43NNTW1wSYlDRz7QIm8rAe0NyXFVNA2BnQlVIJQ1fSnVTY7ECrVg==",
        "LI43NDSMX9JTTUyUTFxwgx6awAjdRCVsvNTW5d1kjFUh+dC+1Mw3V2JRHVBUC6dDrFY=",
        "LI5HDH7tAib9MHiXFVJSZDJElEQlbLzU1lcCNtyMXEQ1WlRgAUgGVg==",
        "LI43bJyUdO0CJnlXxNJWWEXT11p8TM9cV0WyVFSl5EIVVg==",
        "LI43bJyUlNTYBS00RdPXWnxMeOKGlVLSTUxkoDVBVVTbaUeWVg==",
        "LI43bJxUVlP1TM05V9A0ZdPXWgRGlhbkSQJWdRBY8j9xRHaYEGVNVBBEQHtW",
        "LI43bJyUlFSXRNR1tiSEVdUDNkM1dJZIVEkURjFW",
        "LI43bJyUlFSXRNR1tiSEVVE3R1X9wgh/7UL4P3lXFjByDDB/HFRUJdxBrVY=",
        "LI43NMQIX9APTVpmZNRlzBBBJWy81Nbl3TS+NpRkTVTbWU07Vg==",
        "LI43bJyUlNTYdfBZQNYRSFpu9DQ4djTBf/VENVrenVSXjEL9Vg==",
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
        "LI43bJzUUlAyZvTdUfgwNCRsvNRwRuVGEHbfHZjQZrQuUQIe+sGIfmQHNHEYWFRts1jeVw==",
        "LI43NFRVnc1WZ03E1LAOncFWf1GClqxaU0m0TMNc8nogx1XRI0RtVw==",
        "LI5HDH7tACb5sAZVZDDcMTREVN34EEIlbLzU1uXdNL5GlGRNVLiuS5lX",
        "LI43NNTW11hc5EIBkDVxRPohbLyUVJaMEWQhZTTMWFQaDVq1Vw==",
        "LI43NJRQxj/VJH+XFUyLtfRX15cYZF2QjBFkITVWVCQ/WztX",
        "LI43NMQIfe0BJn+XFVJsxAh/bUcNkLX0V0xTOFnMTeRCGXBHdtb931WXMFRBR0KjVw==",
        "LI43NDRsnFSVnFSQC920bkggNCQMXXblp5U0cQIHxJBUiQZY+1c=",
        "LI43NFTX11j8tHT+zJcVU1LTwRRc8OWl5b2VYENUuXBZe1c=",
        "LI43NHRSbEgg1DdwxcEUXEM1bFyQf9WkdFfmXFhXVVR87ll7Vw==",
        "LI43NFRVncFYU00EVObclxVTQNgZ0NVcJ1QrAURBVw==",
        "LI43bJyUdO0CJnFXxFI3ZN1yFlh0lkhUB31beVc=",
        "LI43NBRTVn9xg1a1HtLXFFpcZ2xIIBSVjBBkITVWVGCmR09X",
        "LI43bJyUlNTYBS00RdPXWlhaB9WgAERdQg29ZMfVVZbX3lYBHvpRlsEEBzR2f0V2VNLPQfJX",
        "LI43NDRsnNSUZNSSIwy9JITVVdgDtkaVN14AWFTcsURnVw==",
        "LI43bJxUVWROkhK2b0gg1DdwxcEUXENV/wtd0FNlGNXfVFQKyURnVw==",
        "LI43jJ8kxNVV2DU0e5cYAGXTwVpTSUw0TO9c8npSWMdVObhH01c=",
        "LI43NFTW1wRYV3SiHnTQ3m1IIDQkDN105d00vjaUZE1UBmRHg1c=",
        "LI43NHRYSFpudKQe08GMEExa9jV4dlS0vkVnVw==",
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
        "LI4/jI4k5NU1so7NDzPWDVhYWWf1dme1dhRGeNIbWdJtVPcYfYBQ",
        "LI4/bIyUhFSRRIQ0U7djjBURFLjBFBwcWd5tVFyFTgNQ",
        "LI43NDxsjFSVIlg0VLOPYIxhjPTcFGUMOHFMdt3UkcSsVEoHSPFQ",
        "LI4/DI00hyTk1VXQdfQ1cthbRz8UBocU0E5cVFTAUkk6UA==",
        "LI4/bIyUhNTQTQQsREVSGVI5QFgBYSe5mOEEQQTFXWJHODR2VGV7TtVQ",
        "LI4/bIyUZDW/mOFn45qIjlQwZ2TUHERS3TXc+Mg0h+RCw04AJ1QijH1QUA==",
        "LI4/5D1sjJRUklhEVDKXEbV2HEx85kaa49XfmBDc1lRU21dLg1A=",
        "LI4/bIyUhNTQTQQsLBE4MvrJ7UKW09/4yO1GclZUJBR2zVA=",
        "LI4/bIyUhFSXf084TERoNhHUTM9cVNyId9VQ",
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
        "LI4/bIyUhFSXf09MTERofHIDUFQ+fHapUQ==",
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
        fl_font(FL_FREE_FONT + 1, 13);
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

Window::Window(int width, int height, const char *title)
    : Fl_Double_Window(width, height, title)
{
    // 参数 width height title 均被忽略

    // 设置标题栏图标
    extern HINSTANCE fl_display;
    this->icon((const void *)LoadIcon(fl_display, MAKEINTRESOURCE(IDI_ICON)));

    // 设置窗口标题
    this->label("PvZ Toolkit - 植物大战僵尸全版本辅助工具");

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
                input_sun = new Fl_Value_Input(c(1) + 40, r(1), iw, ih, "〇  ");
                button_sun = new Fl_Button(c(2) + 40, r(1), iw - 40, ih, "阳光");
                input_money = new Fl_Value_Input(c(1) + 40, r(2), iw, ih, "10x  ");
                button_money = new Fl_Button(c(2) + 40, r(2), iw - 40, ih, "金币");
                check_auto_collect = new Fl_Check_Button(c(1), r(3), iw - 15, ih, "自动收集");
                check_no_falling = new Fl_Check_Button(c(2), r(3), iw, ih, "死后不掉钱");
                check_fertilizer = new Fl_Check_Button(c(3) + 10, r(1), iw - 15, ih, "花肥无限");
                check_bug_spray = new Fl_Check_Button(c(4), r(1), iw, ih, "杀虫剂无限");
                check_tree_food = new Fl_Check_Button(c(3) + 10, r(2), iw - 15, ih, "树肥无限");
                check_chocolate = new Fl_Check_Button(c(4), r(2), iw, ih, "巧克力无限");
                input_wisdom_tree = new Fl_Value_Input(c(3) + 13, r(3), iw - 13 + 15, ih, "");
                button_wisdom_tree = new Fl_Button(c(4) + 15, r(3), iw - 15, ih, "智慧树");
                check_free_planting = new Fl_Check_Button(c(1), r(4), iw - 15, ih, "免费用卡");
                check_planting_anywhere = new Fl_Check_Button(c(2), r(4), iw - 15, ih, "随意放置");
                check_fast_belt = new Fl_Check_Button(c(3), r(4), iw - 15, ih, "连续传送");
                check_lock_shovel = new Fl_Check_Button(c(4), r(4), iw - 15, ih, "锁定铲子");
                choice_mode = new Fl_Choice_(c(1), r(5), iw + m + iw + 20, ih, "");
                choice_adventure = new Fl_Choice_(c(3) + 20, r(5), iw - 20 + 15, ih, "");
                button_mix = new Fl_Button(c(4) + 15, r(5), iw - 15, ih, "混乱关卡");
                input_level = new Fl_Value_Input(c(3) + 20, r(6), iw - 20 + 15, ih, "");
                button_level = new Fl_Button(c(4) + 15, r(6), iw - 15, ih, "无尽轮数");
                button_unlock = new Fl_Button(c(1), r(6), iw + 12, ih, "解锁游戏");
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
                check_lock_butter = new Fl_Check_Button(c(1), r(6), iw - 15, ih, "锁定黄油");
                check_no_crater = new Fl_Check_Button(c(2), r(6), iw - 15, ih, "不留弹坑");
                check_no_ice_trail = new Fl_Check_Button(c(3), r(6), iw - 15, ih, "不留冰道");
                check_zombie_not_explode = new Fl_Check_Button(c(4), r(6), iw - 15, ih, "小丑不爆");
            }
            group_battle->end();

            group_lineup = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "阵型");
            {
                choice_slot = new Fl_Choice_(c(1), r(1), iw - 10, ih, "");
                choice_seed = new Fl_Choice_(c(2) - 10, r(1), iw + 10 + 40, ih, "");
                button_seed = new Fl_Button(c(3) + 40, r(1), iw - 40 + 20, ih, "换卡片");
                check_seed_imitater = new Fl_Check_Button(c(4) + 20, r(1), iw - 20, ih, "模仿者");
                check_lineup_mode = new Fl_Check_Button(c(1), r(2), iw + 15, ih, "快捷布阵模式");
                button_auto_ladder = new Fl_Button(c(2) + 15, r(2), iw - 15, ih, "智能搭梯");
                button_put_lily_pad = new Fl_Menu_Button(c(3), r(2), iw, ih, "水路睡莲");
                button_put_flower_pot = new Fl_Menu_Button(c(4), r(2), iw, ih, "屋顶花盆");
                button_capture = new Fl_Button(c(1), r(3), iw + 15, ih, "窗口截图");
                choice_scene = new Fl_Choice_(c(2) + 15, r(3), iw - 15, ih, "");
                choice_lineup_name[0] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[1] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[2] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[3] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[4] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                choice_lineup_name[5] = new Fl_Choice_(c(3), r(3), iw * 2 + 10, ih, "");
                buffer_lineup_string = new Fl_Text_Buffer();
                editor_lineup_string = new Fl_Text_Editor(c(1), r(4), iw * 4 + 10 * 3, ih * 2 + 10 + 2, "");
                button_get_lineup = new Fl_Button(c(1), r(6), iw - 10, ih, "获取代码");
                button_copy_lineup = new Fl_Button(c(2) - 10, r(6), iw - 10, ih, "复制导出");
                button_paste_lineup = new Fl_Button(c(3) + 10 + 10, r(6), iw - 10, ih, "粘贴导入");
                button_set_lineup = new Fl_Button(c(4) + 10, r(6), iw - 10, ih, "布置阵型");
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
                button_spawn_mode = new Fl_Menu_Button(c(4) - 55, r(6), iw + 55 - 5, ih, "选择刷怪模式:");
            }
            group_spawn->end();

            group_others = new Fl_Group(m, m + th, w - m * 2, h - m * 2 - th, "杂项");
            {
                choice_music = new Fl_Choice_(c(1), r(1), iw + 75, ih, "");
                button_music = new Fl_Button(c(2) + 75, r(1), iw, ih, "背景音乐");
                button_userdata = new Fl_Button(c(4) - 15, r(1), iw + 15, ih, "存档文件夹");
                check_no_fog = new Fl_Check_Button(c(1), r(2), iw - 15, ih, "清除浓雾");
                check_see_vase = new Fl_Check_Button(c(2) - 15, r(2), iw - 15, ih, "罐子透视");
                check_background = new Fl_Check_Button(c(3) - 30, r(2), iw + 15, ih, "允许后台运行");
                check_readonly = new Fl_Check_Button(c(4) - 15, r(2), iw + 15, ih, "禁止存档删档");
                button_file = new Fl_Button(c(1), r(3), iw - 20, ih, "选择文件");
                input_file = new Fl_Input(c(2) - 20, r(3), iw + 20 + m + iw + 45, ih, "");
                button_unpack = new Fl_Button(c(4) + 45, r(3), iw - 45, ih, "解包");
                button_dir = new Fl_Button(c(1), r(4), iw - 20, ih, "选择目录");
                input_dir = new Fl_Input(c(2) - 20, r(4), iw + 20 + m + iw + 45, ih, "");
                button_pack = new Fl_Button(c(4) + 45, r(4), iw - 45, ih, "打包");
                choice_debug = new Fl_Choice_(c(1), r(5), iw - 30, ih, "");
                button_debug = new Fl_Button(c(2) - 30, r(5), iw - 40, ih, "调试");
                choice_speed = new Fl_Choice_(c(3) - 70 + 10, r(5), iw - 30, ih, "");
                button_speed = new Fl_Button(c(4) - 100 + 10, r(5), iw - 40, ih, "速度");
                check_limbo_page = new Fl_Check_Button(c(4) - 15, r(5), iw + 15, ih, "显示隐藏关卡");
                choice_scheme = new Fl_Choice_(c(1), r(6), iw - 15, ih, "");
                check_tooltips = new Fl_Check_Button(c(2) - 15, r(6), iw + 35, ih, "English Tooltips");
                button_document = new Fl_Button(c(3) + 30, r(6), iw - 15, ih, "帮助");
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
        game_status_tip = new Fl_Box(430, 12, 10, 25, "");
    }
    this->end();

    // 出怪详情窗体
    // 表格大小 837 x 617
    window_spawn = new Fl_Double_Window(5 + 837 + 5, 5 + 617 + 7, "出怪数量统计");
    {
        table_spawn = new SpawnTable(5, 5, 837, 617);
        button_update_details = new Fl_Button(5, 5, 75, 18 + 3, "···");
        box_mask_spawn_types = new Fl_Box(5, 5 + 18 + 3, 75, 18 * 33, nullptr);
    }
    window_spawn->end();

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
    input_wisdom_tree->bounds(0, 2147483647);
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

    // 1009 * 2 + 2 = 2020
    input_level->bounds(0, 53687091);
    input_level->value(1009);

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

    button_lawn_mower->add("   启动 ", 0, cb_lawn_mower, this);
    button_lawn_mower->add("   删除 ", 0, cb_lawn_mower, this);
    button_lawn_mower->add("   恢复 ", 0, cb_lawn_mower, this);

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
        button_put_lily_pad->add(label.c_str(), 0, cb_put_lily_pad, this);
    }

    for (size_t i = 0; i < 7; i++)
    {
        std::string label;
        for (unsigned int c = 1; c <= 9; c++)
            label += (flower_pot_col_lower[i] <= c && c <= flower_pot_col_upper[i])
                         ? "■"
                         : "□";
        button_put_flower_pot->add(label.c_str(), 0, cb_put_flower_pot, this);
    }

    choice_scene->add("白天");
    choice_scene->add("黑夜");
    choice_scene->add("泳池");
    choice_scene->add("雾夜");
    choice_scene->add("屋顶");
    choice_scene->add("月夜");

    choice_scene->value(2); // 泳池

    choice_lineup_name[0]->hide();
    choice_lineup_name[1]->hide();
    // choice_lineup_name[2]->hide();
    choice_lineup_name[3]->hide();
    choice_lineup_name[4]->hide();
    choice_lineup_name[5]->hide();

#ifdef _DEBUG
    assert(sizeof(lineup_names) == sizeof(lineup_strings));
    assert(sizeof(uintptr_t) == 4);
#endif
    uint32_t lineup_count_total = sizeof(lineup_names) / 4;

    lineup_count[0] = 0;
    lineup_count[1] = 0;
    lineup_count[2] = 0;
    lineup_count[3] = 0;
    lineup_count[4] = 0;
    lineup_count[5] = 0;

    for (size_t i = 0; i < lineup_count_total; i++)
    {
        std::string name = std::string(lineup_names[i]);
        char *scene_str[] = {"[DE]", "[NE]", "[PE]", "[FE]", "[RE]", "[ME]"};
        for (size_t scene = 0; scene < 6; scene++)
        {
            if (name.find(scene_str[scene]) != std::string::npos)
            {
                choice_lineup_name[scene]->add(lineup_names[i]);
                lineup_count[scene]++;
                break;
            }
        }
    }

    char *default_lineup[] = {"[DE].双冰六炮", "[NE].快六炮",
                              "[PE].经典八炮", "[FE].经典八炮",
                              "[RE].天台十炮", "[ME].月夜十炮"};
    for (size_t scene = 0; scene < 6; scene++)
    {
        unsigned int index = 0;
        for (size_t i = 0; i < scene; i++)
            index += lineup_count[i];

        for (size_t i = 0; i < lineup_count[scene]; i++)
        {
            if (strcmp(lineup_names[index + i], default_lineup[scene]) == 0)
            {
                choice_lineup_name[scene]->value(i);
                break;
            }
        }
    }

    editor_lineup_string->buffer(buffer_lineup_string);
    editor_lineup_string->wrap_mode(Fl_Text_Editor::WRAP_AT_BOUNDS, 0);
    editor_lineup_string->deactivate(); // 不可编辑

#ifdef _DEBUG
    size_t lineup_length_total = 0;
    for (size_t i = 0; i < lineup_count_total; i++)
        lineup_length_total += std::string(lineup_strings[i]).size();
    std::cout << "lineup string length avg: " << (lineup_length_total / lineup_count_total) << std::endl;
#endif

    // 出怪名称
    for (size_t i = 0; i < 20; i++)
        check_zombie[i]->label(zombies_zh[spawn_type[i]]);

    // 非旗帜波红眼权重范围
    for (size_t w = 1000; w <= 6000; w += 100)
        choice_giga_weight->add(std::to_string(w).c_str());
    choice_giga_weight->value(0);

    // 默认极限出怪的情况
    choice_giga_weight->deactivate();
    check_giga_limit->activate();

    button_spawn_extra->add(" 清空已选 ", 0, cb_clear_checked_zombies, this);
    button_spawn_extra->add(" 取消限制 ", 0, cb_disable_limit_species, this);
    button_spawn_extra->type(Fl_Menu_Button::POPUP3);
    button_spawn_extra->value(0);

    button_spawn_mode->add("自然出怪 (游戏生成)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->add("极限出怪 (均匀填充)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->add("模拟出怪 (加权随机)", 0, cb_switch_spawn_mode, this);
    button_spawn_mode->type(Fl_Menu_Button::POPUP3);
    button_spawn_mode->value(1); // 默认极限刷怪

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

    button_sun->callback(cb_set_sun, this);
    button_money->callback(cb_set_money, this);
    check_auto_collect->callback(cb_auto_collect, this);

    check_no_falling->callback(cb_no_falling, this);
    check_fertilizer->callback(cb_fertilizer, this);
    check_bug_spray->callback(cb_bug_spray, this);
    check_tree_food->callback(cb_tree_food, this);
    check_chocolate->callback(cb_chocolate, this);
    button_wisdom_tree->callback(cb_wisdom_tree, this);

    check_free_planting->callback(cb_free_planting, this);
    check_planting_anywhere->callback(cb_planting_anywhere, this);
    check_fast_belt->callback(cb_fast_belt, this);
    check_lock_shovel->callback(cb_lock_shovel, this);

    choice_mode->callback(cb_mode, this); // cb_tooltips
    choice_adventure->callback(cb_tooltips, this);
    button_mix->callback(cb_mix_mode, this);
    button_level->callback(cb_level, this);

    button_unlock->callback(cb_unlock, this);
    button_direct_win->callback(cb_direct_win, this);

    choice_row->callback(cb_tooltips, this);
    choice_col->callback(cb_tooltips, this);
    choice_plant->callback(cb_tooltips, this);
    choice_zombie->callback(cb_tooltips, this);

    button_put_plant->callback(cb_put_plant, this);
    button_put_zombie->callback(cb_put_zombie, this);
    button_put_ladder->callback(cb_put_ladder, this);
    button_put_grave->callback(cb_put_grave, this);
    button_put_rake->callback(cb_put_rake, this);

    button_lawn_mower->callback(cb_lawn_mower, this);
    choice_item->callback(cb_tooltips, this);
    button_clear->callback(cb_clear, this);

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

    choice_slot->callback(cb_get_seed, this); // cb_tooltips
    choice_seed->callback(cb_tooltips, this);
    button_seed->callback(cb_set_seed, this);

    check_lineup_mode->callback(cb_lineup_mode, this);
    button_auto_ladder->callback(cb_auto_ladder, this);
    button_capture->callback(cb_capture, this);
    choice_scene->callback(cb_switch_lineup_scene, this); // cb_tooltips
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
    button_set_spawn->callback(cb_set_spawn, this);

    choice_music->callback(cb_tooltips, this);
    button_music->callback(cb_music, this);
    button_userdata->callback(cb_userdata, this);

    check_no_fog->callback(cb_no_fog, this);
    check_see_vase->callback(cb_see_vase, this);
    check_background->callback(cb_background, this);
    check_readonly->callback(cb_readonly, this);

    button_file->callback(cb_open_file, this);
    button_dir->callback(cb_open_dir, this);
    button_unpack->callback(cb_unpack, this);
    button_pack->callback(cb_pack, this);

    choice_debug->callback(cb_tooltips, this);
    button_debug->callback(cb_debug_mode, this);
    choice_speed->callback(cb_tooltips, this);
    button_speed->callback(cb_speed, this);
    check_limbo_page->callback(cb_limbo_page, this);

    choice_scheme->callback(cb_scheme, this); // cb_tooltips
    check_tooltips->callback(cb_tooltips, this);
    button_document->callback(cb_document, this);
    button_about->callback(cb_about, this);

    window_spawn->callback(cb_on_hide_details, this);

    // 根据系统换字体

    DWORD dwVersion = 0;
    DWORD dwBuild = 0;
    dwVersion = GetVersion();
    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));

    if (dwBuild >= 6000)
    {
        // Vista 及以上版本自带雅黑字体
        yahei = true;
    }
    else
    {
        yahei = false;
        std::string fonts_path = "C:\\Windows\\Fonts";
        for (const auto &entry : std::filesystem::directory_iterator(fonts_path))
        {
            std::filesystem::path file_name = entry.path().filename();
            if (file_name == "msyh.ttf" || file_name == "msyh.ttc")
            {
                // std::cout << entry.path() << std::endl;
                yahei = true;
                break;
            }
        }
        if (!yahei)
        {
            // XP 系统肯定没法正常访问植僵工具箱的，只给出方法让用户自己操作
            MessageBoxW(nullptr, L"系统缺少 Microsoft YaHei 字体, 建议安装并启用 ClearType 以得到最佳的界面体验."
                                 L"\n\n"
                                 L"可以在搜索引擎中检索 \"微软雅黑 XP\" 等关键词来查找字体下载和安装方法."
                                 L"\n"
                                 L"控制面板 → 显示 → 外观 → 效果 → 使用下列方式使屏幕字体的边缘平滑: 清晰.",
                        L"缺少界面字体", MB_OK);
        }
    }

    static Fl_Font ui_font = (FL_FREE_FONT + 1); // 主界面
    static Fl_Font ls_font = (FL_FREE_FONT + 2); // 阵型代码
    static Fl_Font tt_font = (FL_FREE_FONT + 3); // 提示信息
    Fl::set_font(ui_font, yahei ? "Microsoft YaHei" : "SimSun");
    Fl::set_font(ls_font, "Courier New");
    Fl::set_font(tt_font, "Segoe UI");

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
    table_spawn->labelfont(ui_font);
    button_update_details->labelfont(ui_font);
    button_update_details->labelsize(12);

    // 工具提示的样式
    Fl_Tooltip::delay(0.1f);
    Fl_Tooltip::hoverdelay(10.0f + 0.1f);
    Fl_Tooltip::hidedelay(10.0f);
    Fl_Tooltip::color(FL_WHITE);
    Fl_Tooltip::textcolor(FL_BLACK);
    Fl_Tooltip::font(tt_font);
    Fl_Tooltip::size(12);
    Fl_Tooltip::margin_width(5);
    Fl_Tooltip::margin_height(5);
    Fl_Tooltip::wrap_width(400);

    emoji = dwBuild >= 9200;

    if (emoji)
    {
        input_sun->copy_label("☀️");
        button_wisdom_tree->copy_label("🌳 智慧树");
        button_unlock->copy_label("🏆 解锁游戏");
        button_lawn_mower->replace(0, " ➡️  启动 ");
        button_lawn_mower->replace(1, " 🆑  删除 ");
        button_lawn_mower->replace(2, " 🔄  恢复 ");
        button_capture->copy_label("📷 窗口截图");
        button_spawn_extra->replace(0, " ❌ 清空已选 ");
        button_spawn_extra->replace(1, " ❎ 取消限制 ");
        button_show_details->copy_label("📈 查看详情");
        button_music->copy_label("🎵 背景音乐");
        button_userdata->copy_label("💾 存档文件夹");
        button_document->copy_label("🌏 帮助");
    }

    // 默认运行的回调函数

    // 获取阵型的字符串
    choice_scene->do_callback();

    // 设置控件工具提示
    check_tooltips->do_callback();

    // 工作类

    pvz = new PvZ();
    pvz->callback(cb_find_result, this);
    // pvz->FindPvZ(); // 在 main() 里调用

    pak = new PAK();

    // this->show(); // 在 main() 里带参调用

    ReadSettings(); // 读取设置
}

Window::~Window()
{
    WriteSettings(); // 保存设置

    delete pak;
    delete pvz;
}

void Window::ReadSettings()
{
    // bool first_open = true;

    HKEY hKey;
    DWORD r = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Cube Studio\\PvZ Toolkit\\v1", //
                            0, KEY_QUERY_VALUE, &hKey);
    if (r == ERROR_SUCCESS)
    {
        // first_open = false;

        LSTATUS status;
        DWORD dwType;
        DWORD dwSize;

        wchar_t lang[15];    // 界面语言
        DWORD scale;         // 缩放倍率
        int scheme;          // 界面样式
        wchar_t zombies[20]; // 已选出怪
        int mode;            // 出怪模式

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
        else
        {
            // 0804  2052  zh-CN  Chinese (Simplified) - China
            // 0404  1028  zh-TW  Chinese (Traditional) - Taiwan
            // 0C04  3076  zh-HK  Chinese - Hong Kong SAR
            // 1404  5124  zh-MO  Chinese - Macao SAR
            // 1004  4100  zh-SG  Chinese - Singapore
            LANGID li = GetUserDefaultLangID();
            // std::cout << "LangID: " << li << std::endl;
            // 非中文区域显示英语提示框
            if (li != 2052 && li != 1028 && li != 3076 && li != 5124 && li != 4100)
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
            if (factor != 1.0f) // TODO
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

        RegCloseKey(hKey);
    }
}

void Window::WriteSettings()
{
    // 界面语言
    wchar_t langChinese[] = L"简体中文";
    wchar_t langEnglish[] = L"English";

    // 缩放倍率
    float scale = Fl::screen_scale(this->screen_num());

    // 界面样式
    int scheme = choice_scheme->value();

    // 已选出怪
    wchar_t zombies[20] = {0};
    for (size_t i = 0; i < 20; i++)
        zombies[i] = (this->check_zombie[i]->value() == 1 ? L'1' : L'0');

    // 出怪模式
    int mode = button_spawn_mode->value();

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

std::string Window::convert_lineup(const std::string &str)
{
    auto split = [](const std::string &str, char seperator) -> std::vector<std::string>
    {
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

    auto hex2dec = [](const std::string &str) -> long
    {
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

        if (item_type < 0 || item_type > 0x32)
            continue;

        if (item_type == 16 || item_type == 33) // 睡莲 花盆
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            base[item_row * 9 + item_col] = (item_type == 16) ? 1 : 2;
            base_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 50) // 墓碑
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            base[item_row * 9 + item_col] = 3;
            base_im[item_row * 9 + item_col] = 0;
        }
        else if (item_type == 30) // 南瓜
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            pumpkin[item_row * 9 + item_col] = 1;
            pumpkin_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 35) // 咖啡
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            coffee[item_row * 9 + item_col] = 1;
            coffee_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 48) // 梯子 0x30
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            ladder[item_row * 9 + item_col] = 1;
        }
        else if (item_type == 49) // 钉耙 0x31
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            rake_row = item_row + 1;
        }
        else // 主要植物
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            int item_state_row = atoi(item_str[3].c_str());
            bool item_imitater = item_str[5] == "1";
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
    bool on = check_tooltips->value() == 1;

    switch (result)
    {
    case PVZ_1_0_0_1051_EN:
        game_status->label("1.0.0.1051 英文原始版");
        game_status->tooltip(on ? "1.0.0.1051 Original (en)" : nullptr);
        break;
    case PVZ_1_2_0_1065_EN:
        game_status->label("1.2.0.1065 英文修复版");
        game_status->tooltip(on ? "1.2.0.1065 Original (en)" : nullptr);
        break;
    case PVZ_1_0_4_7924_ES:
        game_status->label("1.0.4.7924 西班牙语版");
        game_status->tooltip(on ? "1.0.4.7924 Original (es)" : nullptr);
        break;
    case PVZ_1_0_7_3556_ES:
        game_status->label("1.0.7.3556 西班牙语版");
        game_status->tooltip(on ? "1.0.7.3556 Original (es)" : nullptr);
        break;
    case PVZ_1_2_0_1073_EN:
        game_status->label("1.2.0.1073 英文年度版");
        game_status->tooltip(on ? "1.2.0.1073 GOTY (en)" : nullptr);
        break;
    case PVZ_1_2_0_1096_EN:
        game_status->label("1.2.0.1096 Steam 英文年度版");
        game_status->tooltip(on ? "1.2.0.1096 GOTY Steam (en)" : nullptr);
        break;
    case PVZ_1_2_0_1093_DE_ES_FR_IT:
        game_status->label("1.2.0.1093 多国语言年度版");
        game_status->tooltip(on ? "1.2.0.1093 GOTY (de/es/fr/it)" : nullptr);
        break;
    case PVZ_1_1_0_1056_ZH:
        game_status->label("1.1.0.1056 粘度汗化版");
        game_status->tooltip(on ? "1.1.0.1056 GOTY (zh)" : nullptr);
        {
            int ret = MessageBoxW(GetActiveWindow(),                                  //
                                  L"这个版本的游戏存在严重的问题, 随时可能会崩溃.\n"  //
                                  L"建议更换使用其他能正常运行的版本, 现在去下载吗?", //
                                  L"温馨提示",                                        //
                                  MB_OKCANCEL | MB_ICONWARNING);
            if (ret == IDOK)
                ShellExecuteW(nullptr, L"open", L"https://pvz.lmintlcx.com/download/", //
                              nullptr, nullptr, SW_SHOWNORMAL);
        }
        break;
    case PVZ_1_1_0_1056_JA:
        game_status->label("1.1.0.1056 日文年度版");
        game_status->tooltip(on ? "1.1.0.1056 GOTY (ja)" : nullptr);
        break;
    case PVZ_1_1_0_1056_ZH_2012_06:
        game_status->label("1.1.0.1056 年度汉化加强版");
        game_status->tooltip(on ? "1.1.0.1056 GOTY 2012.06 (zh)" : nullptr);
        break;
    case PVZ_1_1_0_1056_ZH_2012_07:
        game_status->label("1.1.0.1056 年度汉化加强版");
        game_status->tooltip(on ? "1.1.0.1056 GOTY 2012.07 (zh)" : nullptr);
        break;
    case PVZ_UNSUPPORTED:
        game_status->label("不支持的游戏版本");
        game_status->tooltip(on ? "Unsupported game version." : nullptr);
        break;
    case PVZ_OPEN_ERROR:
        game_status->label("打开游戏进程出错");
        game_status->tooltip(on ? "Error opening game process." : nullptr);
        break;
    case PVZ_NOT_FOUND:
    default:
        game_status->label("没有找到游戏窗口");
        game_status->tooltip(on ? "No game window was found." : nullptr);
        break;
    }

    // 重新找到游戏时应用所有已选功能
    if (result != PVZ_NOT_FOUND && result != PVZ_OPEN_ERROR && result != PVZ_UNSUPPORTED)
        this->keep_selected_feature();

    if (result == PVZ_NOT_FOUND)
    {
        game_status_tip->label(emoji ? "🛈" : "i");
        game_status_tip->tooltip(on ? "Run Plants vs. Zombies first."
                                    : "先打开运行植物大战僵尸游戏。");
    }
    else if (result == PVZ_OPEN_ERROR)
    {
        game_status_tip->label(emoji ? "🛈" : "i");
        game_status_tip->tooltip(on ? "Try run Pt as administrator."
                                    : "建议用管理员权限运行修改器。");
    }
    else if (result == PVZ_UNSUPPORTED)
    {
        game_status_tip->label(emoji ? "🛈" : "i");
        game_status_tip->tooltip(on ? "Contact author to add support."
                                    : "联系作者给这个版本添加支持。");
    }
    else
    {
        game_status_tip->label("");
        game_status_tip->tooltip(nullptr);
    }

    game_status->redraw();
    game_status_tip->redraw();
}

void Window::keep_selected_feature()
{
    std::vector<Fl_Check_Button *> check_buttons = {
        check_auto_collect,
        check_no_falling,
        check_fertilizer,
        check_bug_spray,
        check_tree_food,
        check_chocolate,
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
        check_limbo_page,
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

void Window::cb_tree_food(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_tree_food();
}

void Window::cb_tree_food()
{
    pvz->TreeFoodUnlimited(check_tree_food->value());
}

void Window::cb_chocolate(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_chocolate();
}

void Window::cb_chocolate()
{
    pvz->ChocolateUnlimited(check_chocolate->value());
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

void Window::cb_mix_mode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_mix_mode();
}

void Window::cb_mix_mode()
{
    int mode = choice_mode->value();
    int level = choice_adventure->value();

    if (mode == 0) // 冒险模式
        level++;

    pvz->MixMode(mode, level);
}

void Window::cb_level(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_level();
}

void Window::cb_level()
{
    pvz->JumpLevel(static_cast<int>(input_level->value()));
}

void Window::cb_unlock(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_unlock();
}

void Window::cb_unlock()
{
    pvz->UnlockTrophy();
}

void Window::cb_direct_win(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_direct_win();
}

void Window::cb_direct_win()
{
    HANDLE hThread = CreateThread(nullptr, 0, cb_direct_win_thread, this, 0, nullptr);
    CloseHandle(hThread);
}

DWORD Window::cb_direct_win_thread(void *w)
{
    ((Window *)w)->cb_direct_win_thread();
    return 0;
}

void Window::cb_direct_win_thread()
{
    Fl::lock();
    button_direct_win->deactivate();
    Fl::unlock();
    Fl::awake();

    pvz->DirectWin();

    Fl::lock();
    button_direct_win->activate();
    Fl::unlock();
    Fl::awake();
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

void Window::cb_put_rake(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_rake();
}

void Window::cb_put_rake()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    pvz->PutRake(row, col);
}

void Window::cb_lawn_mower(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_lawn_mower();
}

void Window::cb_lawn_mower()
{
    pvz->SetLawnMowers(button_lawn_mower->value());
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
    case 2: // 梯子
        pvz->ClearGridItems({3});
        break;
    case 3: // 墓碑
        pvz->ClearGridItems({1});
        break;
    case 4: // 钉耙
        pvz->ClearGridItems({11});
        break;
    default:
        break;
    }
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

    cb_tooltips();
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

void Window::cb_lineup_mode(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_lineup_mode();
}

void Window::cb_lineup_mode()
{
    bool do_do_callback = pvz->IsValid();

    std::vector<Fl_Check_Button *> check_buttons = {
        check_auto_collect,
        check_free_planting,
        check_plant_invincible,
        check_plant_weak,
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
            if (check_buttons[i] == check_plant_weak)
                continue;
            int ori_val = check_buttons[i]->value();
            check_buttons[i]->value(1);
            if (do_do_callback)
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
            if (check_buttons[i] == check_plant_weak)
                continue;
            if (do_do_callback)
                check_buttons[i]->do_callback();
        }
    }
}

void Window::cb_auto_ladder(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_auto_ladder();
}

void Window::cb_auto_ladder()
{
    pvz->AutoLadder(true);
}

void Window::cb_put_lily_pad(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_put_lily_pad();
}

void Window::cb_put_lily_pad()
{
    int i = button_put_lily_pad->value();
    if (i < 0 || i >= 8)
        return;
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
    if (i < 0 || i >= 7)
        return;
    int from_col = flower_pot_col_lower[i];
    int to_col = flower_pot_col_upper[i];
    pvz->FlowerPotOnRoof(from_col, to_col);
}

void Window::cb_capture(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_capture();
}

void Window::cb_capture()
{
    pvz->Screenshot();
}

void Window::cb_switch_lineup_scene(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_switch_lineup_scene();
}

void Window::cb_switch_lineup_scene()
{
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
    int index = 0;
    for (int i = 0; i < choice_scene->value(); i++)
        index += lineup_count[i];
    index += choice_lineup_name[choice_scene->value()]->value();
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

    // try
    // {
    std::regex reg("[0-5](,[a-fA-F0-9]{1,2} [1-6] [1-9] [0-2] [0-4]( [a-zA-Z0-9]{1,}){0,}){0,}");
    if (std::regex_match(str, reg))
    {
        // 网页布阵器格式转成新格式
        str = convert_lineup(str);
    }
    else if (str[0] == 'L')
    {
        // 新格式去掉所有空格
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    }
    // }
    // catch (const std::regex_error &e)
    // {
    //     std::cout << "regex_error: what(): " << e.what() << std::endl;
    // }

    buffer_lineup_string->text(str.c_str());
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

void Window::cb_show_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_show_details();
}

void Window::cb_show_details()
{
    bool on = check_tooltips->value() == 1;

    if (window_spawn->shown() == 0)
    {
        button_show_details->copy_label(emoji ? "📉 隐藏详情" : "隐藏详情");
        button_show_details->copy_tooltip(on ? "Hide Details" : nullptr);

        window_spawn->show();
        cb_update_details();
    }
    else
    {
        button_show_details->copy_label(emoji ? "📈 查看详情" : "查看详情");
        button_show_details->copy_tooltip(on ? "Show Details" : nullptr);

        window_spawn->hide();
    }
}

void Window::cb_update_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_update_details();
}

void Window::cb_update_details()
{
    std::array<int, 1000> zombies_list;
    zombies_list.fill(-1);

    int game_ui = pvz->GameUI();
    if (game_ui != 2 && game_ui != 3)
    {
        // 未进入选卡或者战斗界面
    }
    else
    {
        int game_mode = pvz->GameMode();
        if (game_mode >= 1 && game_mode <= 5)
        {
            zombies_list = pvz->GetSpawnList();
            for (size_t i = 500; i < 1000; i++)
                zombies_list[i] = -1;
        }
        else if (game_mode >= 6 && game_mode <= 15)
        {
            zombies_list = pvz->GetSpawnList();
        }
        else
        {
            // 不支持非生存模式
        }
    }

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

    if (check_tooltips->value() == 1)
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
    window_spawn->size(w, h);
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
        button_spawn_extra->replace(1, emoji ? " ✅ 启用限制 " : " 启用限制 ");
    }
    else
    {
        limit_species = true;
        button_spawn_extra->replace(1, emoji ? " ❎ 取消限制 " : " 取消限制 ");
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
        button_set_spawn->label("自然出怪 (游戏生成)");
        button_set_spawn->tooltip(on ? "Natural (Game Generate)" : nullptr);
        break;

    case 1: // 极限
    default:
        choice_giga_weight->deactivate();
        check_giga_limit->activate();
        button_set_spawn->label("极限出怪 (均匀填充)");
        button_set_spawn->tooltip(on ? "Extreme (Filling Evenly)" : nullptr);
        break;

    case 2: // 模拟
        choice_giga_weight->activate();
        check_giga_limit->activate();
        button_set_spawn->label("模拟出怪 (加权随机)");
        button_set_spawn->tooltip(on ? "Simulate (Weighted Random)" : nullptr);
        break;
    }
}

void Window::cb_set_spawn(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_set_spawn();
}

void Window::cb_set_spawn()
{
    int spawn_mode = button_spawn_mode->value();
    // std::cout << "Spawn Mode: " << spawn_mode << std::endl;

    if (!pvz->GameOn())
        return;
    int game_ui = pvz->GameUI();
    if (game_ui != 2 && game_ui != 3)
        return;
    // 极限和模拟出怪功能仅适用于生存模式
    int game_mode = pvz->GameMode();
    if ((game_mode < 1 || game_mode > 15) && spawn_mode != 0)
        return;

    std::array<bool, 33> zombies = {false};
    for (size_t i = 0; i < 20; i++)
        zombies[spawn_type[i]] = (check_zombie[i]->value() == 1);
    int giga_weight = 1000 + 100 * choice_giga_weight->value();
    bool limit_giga = check_giga_limit->value() == 1;

    switch (spawn_mode)
    {
    case 0: // 自然
        zombies[0] = true;
        pvz->InternalSpawn(zombies);
        break;

    case 1: // 极限
    default:
        zombies[0] = true;
        zombies[1] = true;
        pvz->CustomizeSpawn(zombies, limit_giga, false, 1000);
        break;

    case 2: // 模拟
        zombies[0] = true;
        zombies[1] = true;
        pvz->CustomizeSpawn(zombies, limit_giga, true, giga_weight);
        break;
    }

    if (window_spawn->shown() == 1)
        cb_update_details();
}

void Window::cb_music(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_music();
}

void Window::cb_music()
{
    pvz->SetMusic(choice_music->value() + 1);
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

    switch (ret)
    {
    case UNPACK_SRC_NOT_EXIST:
        MessageBoxW(GetActiveWindow(), L"打开源文件失败！\nUNPACK_SRC_NOT_EXIST", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_SRC_SIZE_ERROR:
        MessageBoxW(GetActiveWindow(), L"获取源文件大小失败！\nUNPACK_SRC_SIZE_ERROR", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_SRC_LOAD_ERROR:
        MessageBoxW(GetActiveWindow(), L"读取源文件内容失败！\nUNPACK_SRC_LOAD_ERROR", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_SRC_HEADER_ERROR:
        MessageBoxW(GetActiveWindow(), L"文件头格式不正确！\nUNPACK_SRC_HEADER_ERROR", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_SRC_DATA_ERROR:
        MessageBoxW(GetActiveWindow(), L"文件数据已经损坏！\nUNPACK_SRC_DATA_ERROR", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_PATH_CREATE_ERROR:
        MessageBoxW(GetActiveWindow(), L"解包路径创建失败！\nUNPACK_PATH_CREATE_ERROR", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_FILE_CREATE_ERROR:
        MessageBoxW(GetActiveWindow(), L"解包文件创建失败！\nUNPACK_FILE_CREATE_ERROR", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_FILE_WRITE_ERROR:
        MessageBoxW(GetActiveWindow(), L"解包文件写入失败！\nUNPACK_FILE_WRITE_ERROR", //
                    L"解包出错", MB_OK | MB_ICONERROR);
        break;
    case UNPACK_SUCCESS:
        MessageBoxW(GetActiveWindow(), std::wstring(L"文件夹位于: \n" + dst_dir).c_str(), //
                    L"解包完成", MB_OK | MB_ICONINFORMATION);
        break;
    default:
        break;
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

    switch (ret)
    {
    case PACK_SRC_NOT_EXIST:
        MessageBoxW(GetActiveWindow(), L"打开源文件夹失败！\nPACK_SRC_NOT_EXIST", //
                    L"打包出错", MB_OK | MB_ICONERROR);
        break;
    case PACK_SRC_EMPTY_ERROR:
        MessageBoxW(GetActiveWindow(), L"源文件夹为空！\nPACK_SRC_EMPTY_ERROR", //
                    L"打包出错", MB_OK | MB_ICONERROR);
        break;
    case PACK_PATH_CREATE_ERROR:
        MessageBoxW(GetActiveWindow(), L"打包路径创建失败！\nPACK_PATH_CREATE_ERROR", //
                    L"打包出错", MB_OK | MB_ICONERROR);
        break;
    case PACK_FILE_CREATE_ERROR:
        MessageBoxW(GetActiveWindow(), L"打包文件创建失败！\nPACK_FILE_CREATE_ERROR", //
                    L"打包出错", MB_OK | MB_ICONERROR);
        break;
    case PACK_FILE_WRITE_ERROR:
        MessageBoxW(GetActiveWindow(), L"打包文件写入失败！\nPACK_FILE_WRITE_ERROR", //
                    L"打包出错", MB_OK | MB_ICONERROR);
        break;
    case PACK_SRC_READ_ERROR:
        MessageBoxW(GetActiveWindow(), L"打包源文件读取失败！\nPACK_SRC_READ_ERROR", //
                    L"打包出错", MB_OK | MB_ICONERROR);
        break;
    case PACK_SUCCESS:
        MessageBoxW(GetActiveWindow(), std::wstring(L"文件位于: \n" + dst_file).c_str(), //
                    L"打包完成", MB_OK | MB_ICONINFORMATION);
        break;
    default:
        break;
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

void Window::cb_speed(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_speed();
}

void Window::cb_speed()
{
    int time_ms[] = {
        1,   // 10x
        2,   // 5x
        5,   // 2x
        10,  // 1x
        20,  // 0.5x
        50,  // 0.2x
        100, // 0.1x
    };
    pvz->SetFrameDuration(time_ms[choice_speed->value()]);
}

void Window::cb_limbo_page(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_limbo_page();
}

void Window::cb_limbo_page()
{
    pvz->UnlockLimboPage(check_limbo_page->value());
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
        vstr_slots.push_back("1st Slot");
        vstr_slots.push_back("2nd Slot");
        vstr_slots.push_back("3rd Slot");
        vstr_slots.push_back("4th Slot");
        vstr_slots.push_back("5th Slot");
        vstr_slots.push_back("6th Slot");
        vstr_slots.push_back("7th Slot");
        vstr_slots.push_back("8th Slot");
        vstr_slots.push_back("9th Slot");
        vstr_slots.push_back("10th Slot");
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

    input_sun->tooltip("0 ~ 9990");
    button_sun->tooltip(on ? "Sun" : nullptr);
    input_money->tooltip("0 ~ 99999");
    button_money->tooltip(on ? "Coins" : nullptr);
    check_auto_collect->tooltip(on ? "Automatic Collect" : nullptr);
    check_no_falling->tooltip(on ? "No Drop After Dead" : nullptr);
    check_fertilizer->tooltip(on ? "Unlimited Fertilizer" : nullptr);
    check_bug_spray->tooltip(on ? "Unlimited Bug Spray" : nullptr);
    check_tree_food->tooltip(on ? "Unlimited Tree Food" : nullptr);
    check_chocolate->tooltip(on ? "Unlimited Chocolate" : nullptr);
    input_wisdom_tree->tooltip("0 ~ 2147483647");
    button_wisdom_tree->tooltip(on ? "Wisdom Tree" : nullptr);
    check_free_planting->tooltip(on ? "Free Planting" : nullptr);
    check_planting_anywhere->tooltip(on ? "Putting Anywhere" : nullptr);
    check_fast_belt->tooltip(on ? "Belt Continuously" : nullptr);
    check_lock_shovel->tooltip(on ? "Lock Shovel" : nullptr);
    choice_mode->tooltip(on ? vstr_modes[choice_mode->value()].c_str() : nullptr);
    choice_adventure->copy_tooltip(on ? choice_adventure->text(choice_adventure->value()) : nullptr);
    button_mix->tooltip(on ? "Modify Mode" : nullptr);
    input_level->tooltip("0 ~ 53687091");
    button_level->tooltip(on ? "Endless Rounds" : nullptr);
    button_unlock->tooltip(on ? "Unlock Trophy" : nullptr);
    button_direct_win->tooltip(on ? "Level Complete" : nullptr);

    choice_row->tooltip(on ? vstr_rows[choice_row->value()].c_str() : nullptr);
    choice_col->tooltip(on ? vstr_cols[choice_col->value()].c_str() : nullptr);
    choice_plant->tooltip(on ? vstr_plants[choice_plant->value()].c_str() : nullptr);
    choice_zombie->tooltip(on ? vstr_zombies[choice_zombie->value()].c_str() : nullptr);
    button_put_plant->tooltip(on ? "Put Plant" : nullptr);
    check_imitater->tooltip(on ? "Imitater" : nullptr);
    button_put_zombie->tooltip(on ? "Put Zombie" : nullptr);
    button_put_ladder->tooltip(on ? "Put Ladder" : nullptr);
    button_put_grave->tooltip(on ? "Put Grave" : nullptr);
    button_put_rake->tooltip(on ? "Put Rake" : nullptr);
    button_lawn_mower->tooltip(on ? "Lawn Mowers" : nullptr);
    choice_item->tooltip(on ? vstr_items[choice_item->value()].c_str() : nullptr);
    button_clear->tooltip(on ? "Clear" : nullptr);
    check_plant_invincible->tooltip(on ? "Plant Invincible" : nullptr);
    check_plant_weak->tooltip(on ? "Plant Weak" : nullptr);
    check_zombie_invincible->tooltip(on ? "Zombie Invincible" : nullptr);
    check_zombie_weak->tooltip(on ? "Zombie Weak" : nullptr);
    check_reload_instantly->tooltip(on ? "Reload Instantly" : nullptr);
    check_mushroom_awake->tooltip(on ? "Mushroom Awake" : nullptr);
    check_stop_spawning->tooltip(on ? "Stop Spawning" : nullptr);
    check_stop_zombies->tooltip(on ? "Stay In Place" : nullptr);
    check_lock_butter->tooltip(on ? "Always Butter" : nullptr);
    check_no_crater->tooltip(on ? "No Crater" : nullptr);
    check_no_ice_trail->tooltip(on ? "No Ice Trail" : nullptr);
    check_zombie_not_explode->tooltip(on ? "Never Explode" : nullptr);

    choice_slot->tooltip(on ? vstr_slots[choice_slot->value()].c_str() : nullptr);
    if (choice_seed->value() == -1)
        choice_seed->tooltip(nullptr);
    else
        choice_seed->tooltip(on ? vstr_plants[choice_seed->value()].c_str() : nullptr);
    button_seed->tooltip(on ? "Change Seed" : nullptr);
    check_seed_imitater->tooltip(on ? "Imitater" : nullptr);
    check_lineup_mode->tooltip(on ? "Quick Lineup Mode" : nullptr);
    button_auto_ladder->tooltip(on ? "Smart Laddering" : nullptr);
    button_put_lily_pad->tooltip(on ? "Lily Pad On Pool" : nullptr);
    button_put_flower_pot->tooltip(on ? "Flower Pot On Roof" : nullptr);
    button_capture->tooltip(on ? "Capture Window" : nullptr);
    choice_scene->tooltip(on ? vstr_scenes[choice_scene->value()].c_str() : nullptr);
    for (size_t i = 0; i < 6; i++)
        choice_lineup_name[i]->tooltip(on ? "(Lineup Name)" : nullptr);
    button_get_lineup->tooltip(on ? "Get Lineup Code" : nullptr);
    button_copy_lineup->tooltip(on ? "Copy To Export" : nullptr);
    button_paste_lineup->tooltip(on ? "Paste To Import" : nullptr);
    button_set_lineup->tooltip(on ? "Apply Current Build" : nullptr);
    editor_lineup_string->tooltip(on ? "(Lineup Code)" : "(阵型代码)");

    for (size_t i = 0; i < 20; i++)
    {
        std::string z = "[" + std::to_string(spawn_type[i]) + "]" //
                        + " " + zombies[spawn_type[i]];
        check_zombie[i]->copy_tooltip(on ? z.c_str() : nullptr);
    }
    if (window_spawn->shown())
        button_show_details->tooltip(on ? "Hide Details" : nullptr);
    else
        button_show_details->tooltip(on ? "Show Details" : nullptr);
    choice_giga_weight->tooltip(on ? "GigaGargantuar\'s weight in non-huge waves."
                                   : "非旗帜波的红眼僵尸随机权重。");
    check_giga_limit->tooltip(on ? "No GigaGargantuar in 11th ~ 19th waves."
                                 : "第 11 ~ 19 波不出红眼僵尸。");
    button_set_spawn->tooltip(on ? "Right click to change spawning mode."
                                 : "右键切换出怪列表生成方法。");

    choice_music->copy_tooltip(on ? choice_music->text(choice_music->value()) : nullptr);
    button_music->tooltip(on ? "Background Music" : nullptr);
    button_userdata->tooltip(on ? "Userdata Folder" : nullptr);
    check_no_fog->tooltip(on ? "Clear Fog" : nullptr);
    check_see_vase->tooltip(on ? "Transparent Vase" : nullptr);
    check_background->tooltip(on ? "Enable Background Running" : nullptr);
    check_readonly->tooltip(on ? "Disable Delete/Save Userdata" : nullptr);
    button_file->tooltip(on ? "Choose File" : nullptr);
    input_file->tooltip(on ? "(File Path)" : "(文件路径)");
    button_unpack->tooltip(on ? "Extract" : nullptr);
    button_dir->tooltip(on ? "Choose Folder" : nullptr);
    input_dir->tooltip(on ? "(Folder Path)" : "(文件夹路径)");
    button_pack->tooltip(on ? "Pack" : nullptr);
    choice_debug->tooltip(on ? vstr_debugs[choice_debug->value()].c_str() : nullptr);
    button_debug->tooltip(on ? "Debug" : nullptr);
    choice_speed->copy_tooltip(on ? choice_speed->text(choice_speed->value()) : nullptr);
    button_speed->tooltip(on ? "Speed" : nullptr);
    check_limbo_page->tooltip(on ? "Unlock Limbo Page" : nullptr);
    choice_scheme->copy_tooltip(on ? choice_scheme->text(choice_scheme->value()) : nullptr);
    check_tooltips->tooltip("English Tooltips");
    button_document->tooltip(on ? "Help" : nullptr);
    button_about->tooltip(on ? "About" : nullptr);

    box_mask_resource->tooltip(on ? "Resources" : nullptr);
    box_mask_battle->tooltip(on ? "Battlefield" : nullptr);
    box_mask_lineup->tooltip(on ? "Lineup" : nullptr);
    box_mask_spawn->tooltip(on ? "Spawning" : nullptr);
    box_mask_others->tooltip(on ? "Others" : nullptr);

    button_update_details->tooltip(on ? "Refresh" : "刷新");

    // 触发重新显示
    if (on && this->shown())
        PostMessageW(fl_xid(this), WM_MOUSEMOVE, 0, MAKELONG(0, 0));

    // 顺便更新标题

    window_spawn->label(on ? "Spawning Counting" : "出怪数量统计");

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
    else if (dpi <= 144)
        title = on ? "PvZ Toolkit " VERSION_NAME
                   : "植物大战僵尸辅助工具";
    else
        title = on ? "PvZ Toolkit"
                   : "植僵工具箱";
    this->copy_label(title.c_str());
}

void Window::cb_about(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_about();
}

void Window::cb_about()
{
    bool on = check_tooltips->value() == 1;

    std::wstring title = std::wstring() + (on ? L"About" : L"关于") + L" " + L"PvZ Toolkit";

    std::wstring version = utf8_decode(VERSION_NAME_FULL) + L" " + L"(" + utf8_decode(BUILD_DATE) + L")";
    std::wstring text = std::wstring()                                                                   //
                        + L"植物大战僵尸辅助工具\n"                                                      //
                        + L"Plants vs. Zombies Toolkit\n"                                                //
                        + L"\n"                                                                          //
                        + (on ? L"Version: " : L"版本号: ") + version + L"\n"                            //
                        + (on ? L"Dependencies: " : L"依赖库: ") + L"FLTK 1.4.x + zlib 1.2.11.x" + L"\n" //
                        + (on ? L"Copyright: " : L"版权所有: ") + L"© 2020-2021 lmintlcx" + L"\n"        //
                        + (on ? L"Credit: " : L"鸣谢: ") + L"a418569882 63enjoy kmtohoem" + L"\n";       //

    SYSTEMTIME time;
    GetLocalTime(&time);
    if (time.wYear > 2009 && time.wMonth == 5 && time.wDay == 5)
    {
        std::wstring date_now = std::to_wstring(time.wYear) + L".05.05";
        std::wstring date_birth = L"2009.05.05";
        text += std::wstring() + L"\n";
        text += std::wstring() + L"🎂 Happy Birthday! (" + date_birth + L"~" + date_now + L")";
    }

    MessageBoxW(GetActiveWindow(), text.c_str(), title.c_str(), MB_OK | MB_ICONINFORMATION);
}

void Window::cb_on_hide_details(Fl_Widget *, void *w)
{
    ((Window *)w)->cb_on_hide_details();
}

void Window::cb_on_hide_details()
{
    button_show_details->copy_label(emoji ? "📈 查看详情" : "查看详情");
    button_show_details->copy_tooltip(check_tooltips->value() == 1 ? "Show Details" : nullptr);

    window_spawn->hide();
}

} // namespace Pt
