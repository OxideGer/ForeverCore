// Traditional Chinese bot names (zhTW), in Traditional characters: the 暱稱 of Taiwanese players, not a character
// conversion of the zhCN list. Taiwanese gamer slang (雷包, 神隊友, 課長, 補師), PTT and Dcard memes (魯蛇, 母湯, 傻眼貓咪,
// 肥宅快樂水, 是在哈囉), night-market food and drink-shop orders (半糖少冰), and local folklore and glove-puppet theatre
// (虎姑婆, 魔神仔, 廖添丁, 史艷文). 2 to 6 characters, as Chinese names are.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& TraditionalChineseNames()
{
    static std::vector<Name> const names = {
        // ---- gamer slang of Taiwan -------------------------------------------------------------------------------------
        { "補師", kAny }, { "小補師", kAny }, { "肉坦", kAny }, { "主坦", kAny }, { "副坦", kAny },
        { "輸出王", kAny }, { "雷包", kAny }, { "雷隊友", kAny }, { "神隊友", kAny }, { "豬隊友", kAny },
        { "坑王", kAny }, { "神手", kAny }, { "手殘", kAny }, { "課長", kAny }, { "課金戰士", kAny },
        { "無課玩家", kAny }, { "小課長", kAny }, { "歐洲人", kAny }, { "臉黑", kAny }, { "歐氣滿滿", kAny },
        { "團長", kAny }, { "開荒團", kAny }, { "滅團", kAny }, { "又滅團", kAny }, { "跑屍", kAny },
        { "回城", kAny }, { "拉怪王", kAny }, { "仇恨王", kAny }, { "斷線王", kAny }, { "延遲爆表", kAny },
        { "沒魔了", kAny }, { "喝水中", kAny }, { "暫離一下", kAny }, { "馬上回來", kAny }, { "救我", kAny },
        { "求復活", kAny }, { "修裝錢", kAny }, { "拍賣場", kAny }, { "賺金幣", kAny }, { "搬磚仔", kAny },
        { "撿裝備", kAny }, { "骰子王", kAny }, { "骰子很爛", kAny }, { "畢業裝", kAny }, { "灰色垃圾", kAny },
        { "帶我飛", kAny }, { "求帶", kAny }, { "抱大腿", kAny }, { "老手", kAny }, { "新手村", kAny },
        { "菜鳥", kAny }, { "萌新", kAny }, { "肝帝", kAny }, { "爆肝", kAny }, { "通宵", kAny },
        { "德魯伊", kAny }, { "小德", kAny }, { "術士", kAny }, { "法師", kAny }, { "獵人", kAny },
        { "盜賊", kAny }, { "戰士", kAny }, { "聖騎", kAny }, { "牧師", kAny }, { "薩滿", kAny },
        { "奶騎", kAny }, { "暗牧", kAny }, { "熊德", kAny }, { "貓德", kAny }, { "鳥德", kAny },
        // ---- races and creatures ----------------------------------------------------------------------------------------
        { "地精", kAny }, { "矮人", kAny }, { "大鬍子", kMale }, { "精靈", kAny }, { "夜精靈", kAny },
        { "牛頭人", kAny }, { "巨魔", kAny }, { "不死族", kAny }, { "骷髏", kAny }, { "綠皮", kAny },
        { "小火球", kAny }, { "冰箱", kAny }, { "變羊術", kAny }, { "小綿羊", kAny }, { "圖騰", kAny },
        { "大黑熊", kAny }, { "台灣黑熊", kAny }, { "石虎", kAny }, { "穿山甲", kAny }, { "藍鵲", kAny },
        { "八哥", kAny }, { "鳳梨", kAny }, { "芒果", kAny }, { "芭樂", kAny }, { "蓮霧", kAny },
        // ---- PTT / Dcard memes and everyday speech ------------------------------------------------------------------
        { "魯蛇", kAny }, { "溫拿", kAny }, { "母湯", kAny }, { "揪咪", kAny }, { "超派", kAny },
        { "很瞎", kAny }, { "傻眼", kAny }, { "傻眼貓咪", kAny }, { "是在哈囉", kAny }, { "我就爛", kAny },
        { "躺平", kAny }, { "佛心", kAny }, { "肥宅", kMale }, { "肥宅快樂水", kAny }, { "邊緣人", kAny },
        { "八七分", kAny }, { "森氣氣", kAny }, { "吼唷", kAny }, { "啾咪", kAny }, { "醬子", kAny },
        { "酷炫", kAny }, { "嘿咻", kAny }, { "安安", kAny }, { "安安你好", kAny }, { "哈囉", kAny },
        { "宅男", kMale }, { "宅女", kFemale }, { "台客", kMale }, { "台妹", kFemale }, { "阿伯", kMale },
        { "阿嬤", kFemale }, { "阿公", kMale }, { "阿姨", kFemale }, { "歐巴桑", kFemale }, { "歐吉桑", kMale },
        { "阿北", kMale }, { "阿宅", kAny }, { "鄉民", kAny }, { "酸民", kAny }, { "老司機", kMale },
        { "工具人", kAny }, { "暖男", kMale }, { "女神", kFemale }, { "男神", kMale }, { "小確幸", kAny },
        { "厭世", kAny }, { "崩潰", kAny }, { "爆氣", kAny }, { "好喔", kAny }, { "真假", kAny },
        { "笑死", kAny }, { "嚇死寶寶", kAny }, { "我先睡", kAny }, { "明天再說", kAny }, { "看心情", kAny },
        // ---- food, drinks and the night market -------------------------------------------------------------------------
        { "滷肉飯", kAny }, { "雞排", kAny }, { "大雞排", kAny }, { "鹽酥雞", kAny }, { "蚵仔煎", kAny },
        { "臭豆腐", kAny }, { "牛肉麵", kAny }, { "小籠包", kAny }, { "鳳梨酥", kAny }, { "芒果冰", kAny },
        { "豆花", kAny }, { "肉圓", kAny }, { "大腸包小腸", kAny }, { "割包", kAny }, { "珍奶", kAny },
        { "手搖飲", kAny }, { "半糖少冰", kAny }, { "全糖去冰", kAny }, { "微糖微冰", kAny }, { "便當", kAny },
        { "排骨便當", kAny }, { "雞腿便當", kAny }, { "滷味", kAny }, { "夜市", kAny }, { "夜市王", kAny },
        { "胡椒餅", kAny }, { "蔥抓餅", kAny }, { "蛋餅", kAny }, { "飯糰", kAny }, { "燒仙草", kAny },
        { "愛玉", kAny }, { "仙草凍", kAny }, { "車輪餅", kAny }, { "雞蛋糕", kAny }, { "地瓜球", kAny },
        { "米血糕", kAny }, { "甜不辣", kAny }, { "擔仔麵", kAny }, { "鍋貼", kAny }, { "牛軋糖", kAny },
        { "太陽餅", kAny }, { "鳳梨蝦球", kAny }, { "麻辣鍋", kAny }, { "薑母鴨", kAny }, { "羊肉爐", kAny },
        { "冬瓜茶", kAny }, { "青草茶", kAny }, { "烏龍茶", kAny }, { "高粱", kAny }, { "台啤", kAny },
        // ---- folklore, temples and glove puppets ----------------------------------------------------------------------
        { "虎姑婆", kFemale }, { "魔神仔", kAny }, { "廖添丁", kMale }, { "史艷文", kMale }, { "素還真", kMale },
        { "布袋戲", kAny }, { "八家將", kAny }, { "電音三太子", kAny }, { "鞭炮", kAny }, { "天燈", kAny },
        { "放天燈", kAny }, { "月下老人", kMale }, { "土地公", kMale }, { "城隍爺", kMale }, { "七爺八爺", kAny },
        { "鍾馗", kMale }, { "關公", kMale }, { "齊天大聖", kMale }, { "八戒", kMale }, { "悟淨", kMale },
        { "三藏", kMale }, { "紅孩兒", kMale }, { "白娘子", kFemale }, { "小青", kFemale }, { "許仙", kMale },
        { "梁山伯", kMale }, { "祝英台", kFemale }, { "孟婆", kFemale }, { "黑面琵鷺", kAny }, { "櫻花鉤吻鮭", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
