// The Simplified Chinese (mainland) catalog of the bots' replies (zhCN; Util/BotLocaleText.h). Keys are the exact English text the code builds
// (`{}` any text, `{?}` any text or none, `{#}` a number, `{$}` money, `{@}` a chat link, `{!}` one word); the stock chatter
// entries are keyed on the database line of migration 0019 with its %placeholders, as in Util/BotLocaleRu.cpp.
//
// Mainland terms (副本, 坦克, 奶妈, 输出) in Simplified characters.
// The same English text may appear more than once: each entry is then one variant, and one is picked at random per line.
// Not translated on purpose (as in the Russian catalog): command words the player types, GM and diagnostic replies, log lines
// and the add-on's ASSIGN| lines. A line missing here reaches the player in English.

#include "BotLocaleText.h"

namespace Playerbot::Locale {

std::vector<Catalog::Entry> const& SimplifiedChineseEntries()
{
    static std::vector<Catalog::Entry> const entries = {
    };
    return entries;
}

std::vector<Catalog::Entry> const& SimplifiedChineseChatterEntries()
{
    static std::vector<Catalog::Entry> const entries = {
    };
    return entries;
}

} // namespace Playerbot::Locale
