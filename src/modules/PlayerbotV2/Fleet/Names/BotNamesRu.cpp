// Russian bot names (ruRU), in Cyrillic: the names Russian-speaking players give their characters. Gamer slang (нагибатор,
// тащер, рачок), internet memes (медвед, превед, ктулху, шлёпа), patronymic and diminutive nicknames (Палыч, Васян),
// food, cartoons and folk tales. Stored form: first letter upper case, rest lower case, at most 12 letters; ё is allowed.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& RussianNames()
{
    static std::vector<Name> const names = {
        // ---- gamer slang and memes ---------------------------------------------------------------------------------------
        { "Нагибатор", kMale }, { "Нагибаторша", kFemale }, { "Нубяра", kAny }, { "Нубас", kAny }, { "Нубик", kAny },
        { "Рачок", kAny }, { "Ракобой", kAny }, { "Раковарка", kAny }, { "Крабик", kAny }, { "Донатер", kMale },
        { "Тащер", kMale }, { "Тащунчик", kAny }, { "Папкан", kMale }, { "Батяня", kMale }, { "Бородач", kMale },
        { "Лутоман", kMale }, { "Лутоед", kAny }, { "Мародёр", kMale }, { "Халявщик", kMale }, { "Афкашник", kMale },
        { "Лагун", kAny }, { "Пингвин", kAny }, { "Агрошка", kAny }, { "Танчик", kAny }, { "Танкистка", kFemale },
        { "Танкист", kMale }, { "Хилка", kFemale }, { "Хилочка", kFemale }, { "Хилерок", kMale }, { "Вайпер", kAny },
        { "Вайпыч", kMale }, { "Фармила", kAny }, { "Фармер", kMale }, { "Голдфармер", kMale }, { "Кемпер", kMale },
        { "Имба", kAny }, { "Изи", kAny }, { "Изикатка", kAny }, { "Катка", kAny }, { "Гоуфаст", kAny },
        { "Кекус", kAny }, { "Ололо", kAny }, { "Трололо", kAny }, { "Пыщьпыщь", kAny }, { "Дратути", kAny },
        { "Медвед", kAny }, { "Превед", kAny }, { "Кросавчег", kMale }, { "Аффтар", kAny }, { "Ктулху", kAny },
        { "Шлёпа", kAny }, { "Ачотакова", kAny }, { "Ничоси", kAny }, { "Авось", kAny }, { "Небось", kAny },
        { "Бобр", kAny }, { "Бобрдобр", kAny }, { "Котэ", kAny }, { "Котейка", kAny }, { "Котофей", kMale },
        { "Кринжик", kAny }, { "Базированный", kMale }, { "Душнила", kAny }, { "Тильтун", kAny }, { "Рофлан", kAny },
        { "Рофлянчик", kAny }, { "Пепега", kAny }, { "Гигачад", kMale }, { "Сигма", kAny }, { "Чилл", kAny },
        // ---- classes and races -----------------------------------------------------------------------------------------
        { "Лекарь", kAny }, { "Знахарка", kFemale }, { "Знахарь", kMale }, { "Шаманюга", kMale }, { "Тотемыч", kMale },
        { "Друлик", kAny }, { "Друля", kAny }, { "Палыч", kMale }, { "Паладинка", kFemale }, { "Варик", kAny },
        { "Чернокнижник", kMale }, { "Ханта", kAny }, { "Хантяра", kAny }, { "Разбойник", kMale }, { "Магичка", kFemale },
        { "Магуля", kFemale }, { "Колдун", kMale }, { "Ведьмочка", kFemale }, { "Ведьмак", kMale }, { "Жрица", kFemale },
        { "Попик", kMale }, { "Батюшка", kMale }, { "Монах", kMale }, { "Варвар", kMale }, { "Берсерк", kMale },
        { "Мишка", kAny }, { "Медведь", kMale }, { "Косолапый", kMale }, { "Совушка", kFemale }, { "Котяра", kMale },
        { "Гномик", kAny }, { "Гномяра", kAny }, { "Дворф", kAny }, { "Бородатый", kMale }, { "Эльфийка", kFemale },
        { "Остроухий", kMale }, { "Орчара", kAny }, { "Зеленый", kAny }, { "Троллина", kAny }, { "Тролльчик", kAny },
        { "Бурёнка", kFemale }, { "Рогатый", kMale }, { "Мертвяк", kAny }, { "Скелетик", kAny }, { "Зомбарь", kAny },
        { "Пушистик", kAny }, { "Зверобой", kMale }, { "Стрелок", kMale }, { "Лучница", kFemale }, { "Огнемёт", kAny },
        { "Ледышка", kAny }, { "Сосулька", kAny }, { "Морозко", kMale }, { "Овечка", kFemale }, { "Барашек", kAny },
        { "Ножичек", kAny }, { "Тенёк", kAny }, { "Невидимка", kAny }, { "Свечка", kAny }, { "Светик", kAny },
        // ---- food and drink --------------------------------------------------------------------------------------------
        { "Пивозавр", kAny }, { "Пельмешка", kAny }, { "Пельмень", kAny }, { "Борщевик", kAny }, { "Борщик", kAny },
        { "Шаурмен", kMale }, { "Шаурмист", kMale }, { "Чебурек", kAny }, { "Сгущёнка", kAny }, { "Сырок", kAny },
        { "Кефирчик", kAny }, { "Квасович", kMale }, { "Самогонщик", kMale }, { "Огурчик", kAny }, { "Холодец", kAny },
        { "Оливье", kAny }, { "Селёдка", kFemale }, { "Винегрет", kAny }, { "Блинчик", kAny }, { "Пирожок", kAny },
        { "Ватрушка", kFemale }, { "Баранка", kFemale }, { "Пряник", kAny }, { "Медовуха", kFemale }, { "Квасик", kAny },
        { "Беляш", kAny }, { "Сушка", kAny }, { "Гречка", kAny }, { "Гречневый", kMale }, { "Майонез", kAny },
        { "Шашлычок", kAny }, { "Дошик", kAny }, { "Окрошка", kAny }, { "Солянка", kAny }, { "Чайник", kAny },
        { "Самовар", kAny }, { "Варенье", kAny }, { "Тушёнка", kAny }, { "Шпроты", kAny }, { "Кабачок", kAny },
        // ---- names, patronymics and nicknames ---------------------------------------------------------------------------
        { "Петрович", kMale }, { "Михалыч", kMale }, { "Кузьмич", kMale }, { "Семёныч", kMale }, { "Степаныч", kMale },
        { "Иваныч", kMale }, { "Саныч", kMale }, { "Васян", kMale }, { "Колян", kMale }, { "Толик", kMale },
        { "Димон", kMale }, { "Серёга", kMale }, { "Лёха", kMale }, { "Вовчик", kMale }, { "Жека", kAny },
        { "Санёк", kMale }, { "Валера", kMale }, { "Гена", kMale }, { "Светка", kFemale }, { "Танюха", kFemale },
        { "Ленусик", kFemale }, { "Машуля", kFemale }, { "Наташка", kFemale }, { "Зинаида", kFemale }, { "Тётямотя", kFemale },
        { "Бабуля", kFemale }, { "Дедуля", kMale }, { "Дядявася", kMale }, { "Тёщенька", kFemale }, { "Кум", kMale },
        { "Красавчик", kMale }, { "Красотка", kFemale }, { "Зайка", kFemale }, { "Котик", kAny }, { "Пупсик", kAny },
        { "Бублик", kAny }, { "Шустрик", kAny }, { "Мямля", kAny }, { "Тормоз", kAny }, { "Тормозок", kAny },
        { "Растяпа", kAny }, { "Балабол", kMale }, { "Хитрован", kMale }, { "Ворчун", kMale }, { "Соня", kAny },
        { "Лентяй", kMale }, { "Лежебока", kAny }, { "Обжора", kAny }, { "Бездельник", kMale }, { "Везунчик", kMale },
        // ---- cartoons, films and folk tales -------------------------------------------------------------------------------
        { "Чебурашка", kAny }, { "Ёжик", kAny }, { "Ёжиквтумане", kAny }, { "Карлсон", kMale }, { "Матроскин", kMale },
        { "Шарик", kAny }, { "Печкин", kMale }, { "Винипух", kAny }, { "Пятачок", kAny }, { "Колобок", kAny },
        { "Кощей", kMale }, { "Бессмертный", kMale }, { "Бабаяга", kFemale }, { "Горыныч", kMale }, { "Иванушка", kMale },
        { "Емеля", kMale }, { "Добрыня", kMale }, { "Алёнушка", kFemale }, { "Василиса", kFemale }, { "Царевна", kFemale },
        { "Несмеяна", kFemale }, { "Богатырь", kMale }, { "Илюша", kMale }, { "Леший", kMale }, { "Водяной", kMale },
        { "Кикимора", kFemale }, { "Домовёнок", kAny }, { "Кузя", kAny }, { "Жарптица", kFemale }, { "Сивкабурка", kAny },
        { "Конёк", kAny }, { "Горбунок", kAny }, { "Щелкунчик", kMale }, { "Буратино", kMale }, { "Мальвина", kFemale },
        { "Карабас", kMale }, { "Дуремар", kMale }, { "Незнайка", kAny }, { "Знайка", kAny }, { "Пончик", kAny },
        { "Крокодилгена", kMale }, { "Шапокляк", kFemale }, { "Волчара", kMale }, { "Нупогоди", kAny }, { "Заяц", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
