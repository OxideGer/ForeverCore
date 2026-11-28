// Korean bot names (koKR), in Hangul: the 닉네임 Korean players choose. Game slang (쪼렙, 만렙, 고인물, 뉴비, 냥꾼, 버스기사),
// internet memes (가즈아, 무야호, 킹받네, 중꺾마, 졌잘싸, 얼죽아, 민초), food (치느님, 치맥, 떡볶이, 붕어빵, 부먹 / 찍먹),
// office-life satire and folk tales. Whole syllables only (the core also accepts jamo such as ㅋ, but a name of them reads
// as noise). At most 12 syllables; most are 2 to 6, as Korean names are.

#include "../BotLocaleNames.h"

namespace Playerbot::V2::Fleet::LocaleNames {

std::vector<Name> const& KoreanNames()
{
    static std::vector<Name> const names = {
        // ---- game slang -------------------------------------------------------------------------------------------------
        { "쪼렙", kAny }, { "만렙", kAny }, { "만렙찍자", kAny }, { "고인물", kAny }, { "뉴비", kAny },
        { "뉴비탈출", kAny }, { "응애뉴비", kAny }, { "딜러", kAny }, { "딜찍누", kAny }, { "딸피", kAny },
        { "탱커", kAny }, { "탱커형", kMale }, { "탱커누나", kFemale }, { "힐러", kAny }, { "힐러찡", kAny },
        { "힐러누나", kFemale }, { "힐러오빠", kMale }, { "딜러오빠", kMale }, { "딜러언니", kFemale }, { "힐좀요", kAny },
        { "마나없음", kAny }, { "물마시는중", kAny }, { "잠수중", kAny }, { "자리비움", kAny }, { "렉걸림", kAny },
        { "핑폭발", kAny }, { "트롤러", kAny }, { "버스기사", kAny }, { "버스승객", kAny }, { "무임승차", kAny },
        { "현질왕", kAny }, { "무과금", kAny }, { "무과금러", kAny }, { "장비병", kAny }, { "파밍왕", kAny },
        { "골드수집가", kAny }, { "경매장큰손", kAny }, { "주사위요정", kAny }, { "입찰왕", kAny }, { "득템", kAny },
        { "득템각", kAny }, { "노득템", kAny }, { "전설템", kAny }, { "회색템", kAny }, { "잡템수집가", kAny },
        { "어그로", kAny }, { "어그로왕", kAny }, { "풀링장인", kAny }, { "막쏘기", kAny }, { "광역딜", kAny },
        { "전멸각", kAny }, { "또전멸", kAny }, { "시체달리기", kAny }, { "부활좀", kAny }, { "수리비", kAny },
        { "와우중독", kAny }, { "오늘만산다", kAny }, { "한판만더", kAny }, { "딱한판", kAny }, { "공대장", kAny },
        { "부공대장", kAny }, { "막공", kAny }, { "고정팟", kAny }, { "길드장", kAny }, { "길마님", kAny },
        // ---- classes and races --------------------------------------------------------------------------------------
        { "흑마법사", kAny }, { "흑마", kAny }, { "법사", kAny }, { "얼음법사", kAny }, { "불법사", kAny },
        { "냥꾼", kAny }, { "냥꾼형", kMale }, { "도적", kAny }, { "은신중", kAny }, { "사제", kAny },
        { "신부님", kMale }, { "수녀님", kFemale }, { "드루", kAny }, { "곰드루", kAny }, { "부엉이", kAny },
        { "주술사", kAny }, { "토템장인", kAny }, { "전사", kAny }, { "분노조절", kAny }, { "방패전사", kAny },
        { "기사님", kAny }, { "보호막", kAny }, { "곰탱이", kAny }, { "고양이", kAny }, { "냥냥", kAny },
        { "멍멍", kAny }, { "꽥꽥", kAny }, { "음메", kAny }, { "양이됨", kAny }, { "변이당함", kAny },
        { "오크전사", kMale }, { "드워프", kAny }, { "수염장인", kMale }, { "노움", kAny }, { "꼬마노움", kAny },
        { "나엘", kAny }, { "나엘누나", kFemale }, { "언데드", kAny }, { "해골", kAny }, { "뼈다귀", kAny },
        { "타우렌", kAny }, { "소고기", kAny }, { "한우", kAny }, { "트롤", kAny }, { "초록이", kAny },
        // ---- internet memes ---------------------------------------------------------------------------------------------
        { "가즈아", kAny }, { "무야호", kAny }, { "킹받네", kAny }, { "어쩔티비", kAny }, { "중꺾마", kAny },
        { "졌잘싸", kAny }, { "알잘딱깔센", kAny }, { "꿀잼", kAny }, { "노잼", kAny }, { "핵인싸", kAny },
        { "아싸", kAny }, { "갓생", kAny }, { "갓생러", kAny }, { "럭키비키", kAny }, { "꿀맛", kAny },
        { "개꿀", kAny }, { "나만아니면돼", kAny }, { "방구석여포", kMale }, { "키보드전사", kAny }, { "손가락전사", kAny },
        { "퇴근각", kAny }, { "칼퇴", kAny }, { "야근왕", kAny }, { "월요병", kAny }, { "불금", kAny },
        { "주말전사", kAny }, { "아재", kMale }, { "아재개그", kMale }, { "인생무상", kAny }, { "현타", kAny },
        { "멘붕", kAny }, { "멘탈갑", kAny }, { "유리멘탈", kAny }, { "쫄보", kAny }, { "겁쟁이", kAny },
        { "허세왕", kAny }, { "관종", kAny }, { "눈팅족", kAny }, { "프로불참러", kAny }, { "만년꼴찌", kAny },
        { "티끌모아", kAny }, { "될놈될", kAny }, { "훈남", kMale }, { "훈녀", kFemale }, { "얼빡", kAny },
        // ---- food and drink -------------------------------------------------------------------------------------------
        { "치킨", kAny }, { "치느님", kAny }, { "치맥", kAny }, { "삼겹살", kAny }, { "떡볶이", kAny },
        { "라면", kAny }, { "라면한그릇", kAny }, { "김치", kAny }, { "김치전", kAny }, { "소맥", kAny },
        { "막걸리", kAny }, { "순대", kAny }, { "어묵", kAny }, { "호떡", kAny }, { "붕어빵", kAny },
        { "짜장면", kAny }, { "짬뽕", kAny }, { "탕수육", kAny }, { "부먹", kAny }, { "찍먹", kAny },
        { "민초", kAny }, { "반민초", kAny }, { "아아", kAny }, { "얼죽아", kAny }, { "뜨아", kAny },
        { "김밥", kAny }, { "참치김밥", kAny }, { "비빔밥", kAny }, { "냉면", kAny }, { "물냉", kAny },
        { "비냉", kAny }, { "족발", kAny }, { "보쌈", kAny }, { "곱창", kAny }, { "닭갈비", kAny },
        { "감자탕", kAny }, { "국밥", kAny }, { "든든국밥", kAny }, { "만두", kAny }, { "군만두", kAny },
        { "계란말이", kAny }, { "떡국", kAny }, { "송편", kAny }, { "약과", kAny }, { "식혜", kAny },
        { "팥빙수", kAny }, { "바나나우유", kAny }, { "컵라면", kAny }, { "편의점", kAny }, { "야식왕", kAny },
        // ---- people and folk tales --------------------------------------------------------------------------------------
        { "막내", kAny }, { "형님", kMale }, { "누님", kFemale }, { "언니", kFemale }, { "오빠", kMale },
        { "할매", kFemale }, { "할배", kMale }, { "김부장", kMale }, { "박과장", kAny }, { "이대리", kAny },
        { "최사원", kAny }, { "인턴", kAny }, { "신입", kAny }, { "사장님", kAny }, { "건물주", kAny },
        { "흥부", kMale }, { "놀부", kMale }, { "심청", kFemale }, { "춘향", kFemale }, { "몽룡", kMale },
        { "홍길동", kMale }, { "전우치", kMale }, { "도깨비", kAny }, { "구미호", kFemale }, { "해태", kAny },
        { "호랑이", kAny }, { "곶감", kAny }, { "선녀", kFemale }, { "나무꾼", kMale }, { "견우", kMale },
        { "직녀", kFemale }, { "토끼전", kAny }, { "별주부", kAny }, { "콩쥐", kFemale }, { "팥쥐", kFemale },
        { "장화홍련", kFemale }, { "까치", kAny }, { "두꺼비", kAny }, { "삽살개", kAny }, { "진돗개", kAny },
    };
    return names;
}

} // namespace Playerbot::V2::Fleet::LocaleNames
