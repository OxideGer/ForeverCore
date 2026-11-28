// Simplified Chinese bot names (zhCN), in Simplified characters: the 昵称 of mainland players. WoW slang of the Chinese
// servers (奶妈, 法爷, 跑尸, 金团, 背锅侠), internet memes (摸鱼, 咸鱼, 打工人, 干饭人, 吃瓜群众, 欧皇, 非酋, 柠檬精),
// food, and figures of the classic novels and legends. The Traditional Chinese pool is its own list with Taiwanese culture
// (Fleet/Names/BotNamesZhTW.cpp). 2 to 6 characters, as Chinese names are.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& SimplifiedChineseNames()
{
    static std::vector<Name> const names = {
        // ---- WoW slang ------------------------------------------------------------------------------------------------
        { "奶妈", kFemale }, { "小奶妈", kFemale }, { "奶爸", kMale }, { "肉盾", kAny }, { "坦克", kAny },
        { "输出", kAny }, { "大腿", kAny }, { "抱大腿", kAny }, { "法爷", kMale }, { "小德", kAny },
        { "小术", kAny }, { "贼哥", kMale }, { "狂暴战", kAny }, { "防战", kAny }, { "奶骑", kAny },
        { "惩戒骑", kAny }, { "暗牧", kAny }, { "奶萨", kAny }, { "增强萨", kAny }, { "猎人哥", kMale },
        { "开荒", kAny }, { "开荒团", kAny }, { "团长", kAny }, { "副团长", kAny }, { "金团", kAny },
        { "老板", kAny }, { "打金", kAny }, { "搬砖", kAny }, { "搬砖党", kAny }, { "拍卖行", kAny },
        { "回城", kAny }, { "跑尸", kAny }, { "灭团", kAny }, { "又灭了", kAny }, { "背锅侠", kMale },
        { "甩锅", kAny }, { "拉怪", kAny }, { "拉多了", kAny }, { "仇恨", kAny }, { "仇恨稳", kAny },
        { "手残党", kAny }, { "手残", kAny }, { "键盘侠", kMale }, { "嘴强王者", kAny }, { "氪金", kAny },
        { "氪金大佬", kAny }, { "白嫖", kAny }, { "白嫖党", kAny }, { "欧皇", kAny }, { "非酋", kAny },
        { "锦鲤", kAny }, { "幸运锦鲤", kAny }, { "大佬", kAny }, { "带带我", kAny }, { "求带", kAny },
        { "求组", kAny }, { "上车", kAny }, { "老司机", kMale }, { "大神", kAny }, { "躺赢", kAny },
        { "划水", kAny }, { "菜鸟", kAny }, { "萌新", kAny }, { "萌妹", kFemale }, { "装备党", kAny },
        { "毕业装", kAny }, { "掉线了", kAny }, { "卡成狗", kAny }, { "延迟高", kAny }, { "蓝没了", kAny },
        { "喝水中", kAny }, { "暂离", kAny }, { "马上回", kAny }, { "复活我", kAny }, { "修装备", kAny },
        // ---- internet memes ---------------------------------------------------------------------------------------------
        { "摸鱼", kAny }, { "摸鱼达人", kAny }, { "佛系玩家", kAny }, { "咸鱼", kAny }, { "咸鱼翻身", kAny },
        { "打工人", kAny }, { "干饭人", kAny }, { "吃货", kAny }, { "老铁", kAny }, { "老六", kAny },
        { "牛人", kAny }, { "厉害了", kAny }, { "稳如老狗", kAny }, { "苟住", kAny }, { "皮皮虾", kAny },
        { "皮一下", kAny }, { "杠精", kAny }, { "柠檬精", kAny }, { "吃瓜群众", kAny }, { "吃瓜", kAny },
        { "围观", kAny }, { "路人甲", kAny }, { "龙套", kAny }, { "内卷", kAny }, { "躺平", kAny },
        { "社恐", kAny }, { "社牛", kAny }, { "夜猫子", kAny }, { "熬夜冠军", kAny }, { "早睡失败", kAny },
        { "秃头少年", kMale }, { "保温杯", kAny }, { "枸杞", kAny }, { "泡脚", kAny }, { "养生达人", kAny },
        { "凡尔赛", kAny }, { "绝绝子", kAny }, { "完蛋了", kAny }, { "破防了", kAny }, { "真香", kAny },
        { "奥利给", kAny }, { "冲鸭", kAny }, { "加油鸭", kAny }, { "好家伙", kAny }, { "离谱", kAny },
        { "离大谱", kAny }, { "就这", kAny }, { "妙啊", kAny }, { "绝了", kAny }, { "整活", kAny },
        // ---- food and drink -------------------------------------------------------------------------------------------
        { "火锅", kAny }, { "麻辣烫", kAny }, { "小龙虾", kAny }, { "烤串", kAny }, { "煎饼果子", kAny },
        { "肉夹馍", kAny }, { "包子", kAny }, { "饺子", kAny }, { "豆汁儿", kAny }, { "臭豆腐", kAny },
        { "螺蛳粉", kAny }, { "奶茶", kAny }, { "珍珠奶茶", kAny }, { "辣条", kAny }, { "可乐鸡翅", kAny },
        { "西红柿炒蛋", kAny }, { "红烧肉", kAny }, { "东坡肉", kAny }, { "宫保鸡丁", kAny }, { "麻婆豆腐", kAny },
        { "鱼香肉丝", kAny }, { "糖醋排骨", kAny }, { "北京烤鸭", kAny }, { "烤鸭", kAny }, { "炸酱面", kAny },
        { "兰州拉面", kAny }, { "热干面", kAny }, { "小笼包", kAny }, { "生煎", kAny }, { "汤圆", kAny },
        { "月饼", kAny }, { "粽子", kAny }, { "糖葫芦", kAny }, { "烤红薯", kAny }, { "烤冷面", kAny },
        { "鸡蛋灌饼", kAny }, { "凉皮", kAny }, { "酸辣粉", kAny }, { "米线", kAny }, { "豆浆油条", kAny },
        { "老坛酸菜", kAny }, { "白开水", kAny }, { "菊花茶", kAny }, { "二锅头", kAny }, { "啤酒肚", kMale },
        // ---- classes and races --------------------------------------------------------------------------------------
        { "术士", kAny }, { "法师", kAny }, { "猎人", kAny }, { "盗贼", kAny }, { "战士", kAny },
        { "圣骑士", kAny }, { "牧师", kAny }, { "萨满", kAny }, { "德鲁伊", kAny }, { "侏儒", kAny },
        { "矮人", kAny }, { "牛头人", kAny }, { "亡灵", kAny }, { "巨魔", kAny }, { "地精", kAny },
        { "暗夜精灵", kAny }, { "小矮子", kAny }, { "大胡子", kMale }, { "牛魔", kAny }, { "绿皮", kAny },
        { "骷髅兵", kAny }, { "小火球", kAny }, { "冰箱", kAny }, { "变羊", kAny }, { "小绵羊", kAny },
        { "图腾", kAny }, { "大熊猫", kAny }, { "猫德", kAny }, { "熊德", kAny }, { "鸟德", kAny },
        // ---- classic novels, legends and history --------------------------------------------------------------------
        { "孙悟空", kMale }, { "齐天大圣", kMale }, { "猪八戒", kMale }, { "沙和尚", kMale }, { "唐僧", kMale },
        { "白骨精", kFemale }, { "哪吒", kMale }, { "嫦娥", kFemale }, { "玉兔", kFemale }, { "月老", kMale },
        { "财神", kAny }, { "土地公", kMale }, { "灶王爷", kMale }, { "张飞", kMale }, { "曹操", kMale },
        { "诸葛亮", kMale }, { "关羽", kMale }, { "赵子龙", kMale }, { "吕布", kMale }, { "貂蝉", kFemale },
        { "林黛玉", kFemale }, { "贾宝玉", kMale }, { "孔乙己", kMale }, { "祥林嫂", kFemale }, { "济公", kMale },
        { "包青天", kMale }, { "花木兰", kFemale }, { "穆桂英", kFemale }, { "武松", kMale }, { "鲁智深", kMale },
        { "葫芦娃", kAny }, { "小龙女", kFemale }, { "黄蓉", kFemale }, { "郭靖", kMale }, { "令狐冲", kMale },
        { "扫地僧", kMale }, { "店小二", kMale }, { "江湖郎中", kMale }, { "侠客", kAny }, { "女侠", kFemale },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
