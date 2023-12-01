#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <windows.h> 
#include <conio.h> 
using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

int validationYear(int year);
int validationMonth(int month);
int validationDay(int day, int month, int year);

int searchZodiac(int day, int month);
void printZodiac(int day, int month);
void printZodiacChina(int year);

void endProgramText();

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleTitle(L"Гороскоп");
    SetConsoleTextAttribute(color, 11);

    /* умовна СТОРІНКА 1 - Стартова */

    cout << endl;
    cout << " ГОРОСКОП" << endl;
    cout << endl;

    /* отримання дати народження */
    int year, month, day;

    cout << " Щоб дiзнатися гороскоп, необхiдно ввести дату народження" << endl << endl;

    cout << " Напишiть рiк народження: ";
mYear:
    SetConsoleTextAttribute(color, 12);
    cin >> year;
    cout << endl;

    bool isValidYear = validationYear(year);
    if (!isValidYear) goto mYear;

    SetConsoleTextAttribute(color, 11);
    cout << " Напишiть номер мiсяця народження (1-12): ";
mMonth:
    SetConsoleTextAttribute(color, 12);
    cin >> month;
    cout << endl;

    bool isValidMonth = validationMonth(month);
    if (!isValidMonth) goto mMonth;

    SetConsoleTextAttribute(color, 11);
    cout << " Напишiть день народження: ";
mDay:
    SetConsoleTextAttribute(color, 12);
    cin >> day;
    cout << endl;

    bool isValidDay = validationDay(day, month, year);
    if (!isValidDay) goto mDay;

    /* умовна СТОРІНКА 2 - Гороспопи */

    /* друк гороскопiв */
    system("cls");
    cout << endl;
    SetConsoleTextAttribute(color, 11);
    cout << " Дата народження: ";
    SetConsoleTextAttribute(color, 12);
    cout << day << "." << month << "." << year << endl << endl;
    SetConsoleTextAttribute(color, 11);
    cout << " ВАШ ГОРОСКОП: \a" << endl << endl;

    cout << " Зодiакальний гороскоп:" << endl << endl;

    printZodiac(day, month);

    cout << " Китайський гороскоп:" << endl << endl;

    printZodiacChina(year);

    /* гороскоп на завтра */
    int tomorrowHoroscope;
    cout << " Хочете дiзнатися свiй гороскоп на завтра?" << endl;
    cout << " Натиснiть 1 якщо ТАК" << endl;
    cout << " Натиснiть будь-яку клавiшу якщо НI" << endl << endl;
    cin >> tomorrowHoroscope;

    /* умовна СТОРІНКА 3 - Гороскоп на завтра */

    switch (tomorrowHoroscope)
    {
    case 1: {
        system("cls");
        system("color E4");
        cout << endl;
        cout << " ЗАВТРА ВСЕ БУДЕ ДОБРЕ :)" << endl << endl;
        break;
    }
          /* умовна СТОРІНКА 4 - Завершення програми */
    default: endProgramText(); break;
    }

    /* повторний запит */
    int repeat;
    cout << " Хочете почати спочатку?" << endl;
    cout << " Натиснiть 1 якщо ТАК" << endl;
    cout << " Натиснiть будь-яку клавiшу якщо НI" << endl;
    cin >> repeat;
    cout << endl;

    switch (repeat)
    {
    case 1: {
        system("cls");
        main();
        break;
    }
          /* умовна СТОРІНКА 4 - Завершення програми  */
    default: endProgramText(); break;
    }
}

int validationYear(int year) {
    SetConsoleTextAttribute(color, 11);

    bool isValidYear = true;

    if (year <= 0 || year >= 2024) {
        cout << " Помилка ... " << endl;
        cout << " Напишiть справжнiй рiк народження ";
        isValidYear = false;
    }
    else if (year > 0 && year < 1900) {
        cout << " Помилка ... " << endl;
        cout << " Можемо визначити гороскоп тiльки народжених пiсля 1900 року ";
        isValidYear = false;
    }
    return isValidYear;
}

int validationMonth(int month) {
    SetConsoleTextAttribute(color, 11);

    bool isValidMonth = true;

    if (month <= 0 || month > 12) {
        cout << " Напишiть мiсяць народження вiд 1 до 12 ";
        isValidMonth = false;
    }
    return  isValidMonth;
}

int validationDay(int day, int month, int year) {
    SetConsoleTextAttribute(color, 11);

    bool isValidDay = true;
    int leapYear2028 = 2028;
    bool leapYear = false;

    for (int i = 0; i <= 5; i++)
    {
        leapYear2028 -= 4;
        if (leapYear2028 == year) leapYear = true;
    }
    leapYear2028 = 2028;

    if (day <= 0) {
        cout << " Напишiть правильний день народження ";
        isValidDay = false;
    }
    else if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
        cout << " У мiсяцi не може бiльше 31 днiв. Напишiть правильни день ";
        isValidDay = false;
    }
    else if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
        cout << " У мiсяцi не може бiльше 30 днiв. Напишiть правильни день ";
        isValidDay = false;
    }
    else if ((day > 28 && month == 2 && !leapYear) || (day > 29 && month == 2 && leapYear)) {
        cout << " У лютому менше днiв. Напишiть правильний день ";
        isValidDay = false;
    }
    return  isValidDay;
}

int searchZodiac(int day, int month) {
    int zodiac = 0;

    switch (month)
    {
    case 1: day <= 20 ? zodiac = 10 : zodiac = 11; break;
    case 2: day <= 18 ? zodiac = 11 : zodiac = 12; break;
    case 3: day <= 20 ? zodiac = 12 : zodiac = 1;  break;
    case 4: day <= 20 ? zodiac = 1 : zodiac = 2; break;
    case 5: day <= 21 ? zodiac = 2 : zodiac = 3; break;
    case 6: day <= 20 ? zodiac = 3 : zodiac = 4; break;
    case 7: day <= 22 ? zodiac = 4 : zodiac = 5; break;
    case 8: day <= 21 ? zodiac = 5 : zodiac = 6; break;
    case 9: day <= 23 ? zodiac = 6 : zodiac = 7; break;
    case 10: day <= 23 ? zodiac = 7 : zodiac = 8; break;
    case 11: day <= 22 ? zodiac = 8 : zodiac = 9; break;
    case 12: day <= 21 ? zodiac = 9 : zodiac = 10; break;
    default: break;
    }
    return zodiac;
}

void printZodiac(int day, int month) {
    int zodiac = searchZodiac(day, month);

    if (zodiac == 1 || zodiac == 5 || zodiac == 9) SetConsoleTextAttribute(color, 12);
    if (zodiac == 2 || zodiac == 6 || zodiac == 10) SetConsoleTextAttribute(color, 14);
    if (zodiac == 3 || zodiac == 7 || zodiac == 11) SetConsoleTextAttribute(color, 9);
    if (zodiac == 4 || zodiac == 8 || zodiac == 12) SetConsoleTextAttribute(color, 11);

    switch (zodiac)
    {
    case 1: {
        cout << " ОВЕН " << endl;
        cout << "  Усi Овни люблять бути номер один, тому не дивно, що цей знак зодiаку — перший у списку. Будучи типовими представниками стихiї вогню, Овни вирiзняються високою енергiйнiстю, iмпульсивнiстю та неабиякою амбiцiйнiстю. Символом цього знака зодiаку є баран iз загнутими рогами, що демонструє агресiю, силу та авторитарнiсть. Якщо говорити про негативнi сторони, то це власне i є надмiрне бажання все контролювати та часом заграватися у диктаторiв." << endl;
        cout << " Стихiя - вогонь " << endl;
        cout << " Колiр - червоний " << endl;
        break;
    }
    case 2: {
        cout << " ТЕЛЕЦЬ " << endl;
        cout << " Тельцi є типовими представниками стихiї землi, тому вони вирiзняються теплотою i пристраснiстю. Характерними рисами для представникiв цих знакiв зодiаку є практичнiсть, консервативнiсть, прагнення до фiнансової стабiльностi та комфорту. Тельцi нiколи не пiдуть на грандiознi ризики заради примарної мрiї чи непевної iдеї, тому авантюрнi подорожi та професiї — не їхня iсторiя. Свiт Тельцiв дуже лаконiчний, логiчний, впорядкований та комфортний. Стабiльнiсть — їхнє все." << endl;
        cout << " Стихiя - земля" << endl;
        cout << " Колiр - жовтий " << endl;
        break;
    }
    case 3: {
        cout << " БЛИЗНЮКИ " << endl;
        cout << " Характеристика знаку зодiаку Близнюки спiвзвучна з його назвою. Роздвоєння особистостi, перепади настрою й пошуки себе найбiльш характернi саме для Близнюкiв. Власне тому вони рiдко вiдчувають абсолютне щастя та гармонiю iз собою. Говорячи про переваги цього знака зодiаку, варто згадати про те, що стихiя повiтря надiляє їх спритнiстю, жвавiстю й комунiкабельнiстю та прагненням до нових висот. Як правило, лише рух дарує їм почуття щастя. " << endl;
        cout << " Стихiя - повiтря " << endl;
        cout << " Колiр - блакитний " << endl;
        break;
    }
    case 4: {
        cout << " РАК" << endl;
        cout << " Людей, якi народились пiд знаком зодiаку Рак, у суспiльствi часто сприймають як складних, загадкових i нелогiчних натур. Здебiльшого так i є. Вони дуже таємничi й закритi для зовнiшнього свiту i важко йдуть на контакт iз новими людьми. Однак за товстою оболонкою приховується чутлива та вразлива натура. До речi, найбiльше хвилюються за амурнi справи та пiддаються впливу негативних зовнiшнiх факторiв саме Раки." << endl;
        cout << " Стихiя - вода" << endl;
        cout << " Колiр - бiрюзовий " << endl;
        break;
    }
    case 5: {
        cout << " ЛЕВ " << endl;
        cout << " Леви — це справжнi королi та королеви джунглiв. Представники цього вогняного знаку з задоволенням приймають свiй королiвський статус: жвавi та запальнi, вони люблять побути в центрi уваги. Не дарма, адже планета покровитель Левiв — Сонце. Правлять цими людьми здебiльшого амбiцiйнiсть, самолюбство та гордiсть. До речi, з останньою вони можуть часто перегинати палицю, так само, як i з жагою лестощiв у свiй бiк." << endl;
        cout << " Стихiя - вогонь" << endl;
        cout << " Колiр - червоний " << endl;
        break;
    }
    case 6: {
        cout << " ДIВА " << endl;
        cout << " Символ Дiви iсторично представляв богинь пшеницi та землеробства. Цей образ говорить сам за себе у матерiальному свiтi. Дiви логiчнi, практичнi та систематичнi у своєму пiдходi до життя. Представники цього знаку зодiаку зазвичай у душi перфекцiонiсти й не бояться вдосконалювати свої навички завдяки стараннiй i послiдовнiй працi. Дiви, як правило, не люблять публiчнiсть, вони рiдко стають центром загальної уваги." << endl;
        cout << " Стихiя - земля" << endl;
        cout << " Колiр - жовтий " << endl;
        break;
    }
    case 7: {
        cout << " ТЕРЕЗИ " << endl;
        cout << " Терези — це повiтряний знак, що знаходиться пiд покровом Венери й Сатурна одразу. Їх символом є ваги — єдиний неживий об’єкт зодiаку, який символiзує концентрацiю на рiвновазi та гармонiї. Терези одержимi симетрiєю i прагнуть досягти балансу у всiх сферах життя. Розсудливiсть, схильнiсть до сумнiвiв — це теж про Терезiв, яким важко даються вибори, особливо життєво важливi." << endl;
        cout << " Стихiя - повiтря" << endl;
        cout << " Колiр - блактний " << endl;
        break;
    }
    case 8: {
        cout << " СКОРПIОН " << endl;
        cout << " Скорпiонiв цiлком заслужено можна назвати представниками одного з найскладнiших за характером знакiв зодiаку. Вони вкрай чутливi та вразливi, однак не схильнi проявляти цi риси на публiцi, волiючи проживати все в собi, або роздiляти з дуже близькими людьми. Заради власних амбiцiй та цiлей Скорпiони можуть навiть забувати про власнi принципи та переконання." << endl;
        cout << " Стихiя - вода" << endl;
        cout << " Колiр - бiрюзовий " << endl;
        break;
    }
    case 9: {
        cout << " СТРIЛЕЦЬ " << endl;
        cout << " Народженi пiд знаком Стрiльця люди, завжди перебувають у пошуку нових знань та емоцiй. Вони заповзятливi, люблять пригоди й подорожi, легкi на пiдйом i схильнi до ризику. Навiть опинившись у незвичних, нових для себе обставинах, представники цього знака не розгубляться й легко знайдуть однодумцiв i друзiв. Товариськiсть i вiдкритiсть допомагає їм легко крокувати життєвим шляхом i долати всi труднощi." << endl;
        cout << " Стихiя - вогонь" << endl;
        cout << " Колiр - червоний " << endl;
        break;
    }
    case 10: {
        cout << " КОЗОРIГ " << endl;
        cout << " Про Козерогiв часто вiдгукуються як про надзвичайно стриманих, органiзованих та практичних осiб. Цi риси часто допомагають досягти неабиякого успiху та тримати всi життєвi ситуацiї пiд контролем. Представники цього знака зазвичай не виносять особистi проблеми й почуття на публiку, а у формуваннi власної репутацiї волiють робити ставку не на екстравагантнiсть або пiдкреслення власної iндивiдуальностi, а на коректну поведiнку й елегантний формалiзм." << endl;
        cout << " Стихiя - земля " << endl;
        cout << " Колiр - жовтий " << endl;
        break;
    }
    case 11: {
        cout << " ВОДОЛIЙ " << endl;
        cout << " Представники знака зодiаку Водолiй часто демонструють свiй статус «в активному пошуку». Мова йде про нову iнформацiю, вiдчуття, подорожi та незвичний досвiд. Водолiї завжди прагнуть до оригiнальностi, яка проявляється буквально у всьому — вiд способу мислення до способу життя. Вони не виставляють напоказ свої досягнення, проте дуже люблять, коли їх iндивiдуальнiсть оцiнюють." << endl;
        cout << " Стихiя - повiтря" << endl;
        cout << " Колiр - блактиний " << endl;
        break;
    }
    case 12: {
        cout << " РИБИ " << endl;
        cout << " Риби — останнiй, 12-й знак Зодiаку, що завершує астрологiчне зодiакальне коло. Риби є одним iз найбiльш суперечливих представникiв зодiакального сузiр’я. Стихiя води визначає мiнливiсть i нестабiльнiсть їх натури. Сузiр’я Риб управляється вiдразу Юпiтером i Нептуном, а тому мiнливiсть характеру забезпечена їм iз самого народження. Найчастiше Риби реалiзовують себе у творчих професiях, якi вимагають частої змiни iмiджу й ходу думок." << endl;
        cout << " Стихiя - вода" << endl;
        cout << " Колiр - бiрюзовий " << endl;
        break;
    }
    default:
        break;
    }

    SetConsoleTextAttribute(color, 11);
    cout << endl;
}

void printZodiacChina(int year) {
    int yearZero = 1900;
    int reducedYear = (year - yearZero) % 12;

    if (reducedYear == 1 || reducedYear == 4 || reducedYear == 7 || reducedYear == 10)
        SetConsoleTextAttribute(color, 14);
    if (reducedYear == 8 || reducedYear == 9) SetConsoleTextAttribute(color, 7);
    if (reducedYear == 0 || reducedYear == 11) SetConsoleTextAttribute(color, 11);
    if (reducedYear == 2 || reducedYear == 3) SetConsoleTextAttribute(color, 6);
    if (reducedYear == 6 || reducedYear == 5) SetConsoleTextAttribute(color, 12);

    switch (reducedYear)
    {
    case 0: {
        cout << " ЩУР або МИША" << endl;
        cout << " Прямий, чiпкий, iнтенсивний, допитливий, харизматичний, чуттєвий, iнтелектуальний, працьовитий, привабливий, красномовний, товариський, художнiй i проникливий.Може бути манiпулятивним, мстивим, схильним до саморуйнування, заздрiсним, брехливим, продажними, впертим, критичним, надто амбiцiйним, безжальним, нетерпимим iнтриганом." << endl;
        cout << " Стихiя - вода" << endl;
        cout << " Колiр - бiрюзовий " << endl;
        break;
    }
    case 1: {
        cout << " БИК або БУЙВОЛ" << endl;
        cout << " Надiйний, амбiтний, спокiйний, методичний, природжений лiдер, терплячий, працьовитий, звичайний, стiйкий, скромний, логiчний, рiшучий, наполегливий. Може бути впертим, догматичним, запальним, недалеким, матерiалiстичним, жорстким, вимогливим." << endl;
        cout << " Стихiя - земля" << endl;
        cout << " Колiр - жовтий " << endl;
        break;
    }
    case 2: {
        cout << " ТИГР" << endl;
        cout << " Непередбачуваний, бунтiвний, барвистий, потужний, пристрасний, смiливий, енергiйний, стимулюючий, щирий, нiжний, гуманний, щедрий. Може бути неспокiйним, нерозважливим, упертим, егоїстичним, агресивним, самостiйним, керованим i похмурим." << endl;
        cout << " Стихiя - дерево" << endl;
        cout << " Колiр - коричневий " << endl;
        break;
    }
    case 3: {
        cout << " КРОЛИК або КIТ" << endl;
        cout << " Милостивий, хороший друг, добрий, чуттєвий, тихий, люб'язний, елегантний, стриманий, обережний, художнiй, ретельний, нiжний, впевнений у собi, сором'язливий, проникливий, жалiсливий, везучий, гнучкий. Може бути примхливим, егоїстом, поверхневим, потурає власним слабкостям, опортунiстичних i впертим." << endl;
        cout << " Стихiя - дерево" << endl;
        cout << " Колiр - коричневий " << endl;
        break;
    }
    case 4: {
        cout << " ДРАКОН" << endl;
        cout << " Великодушний, ставний, енергiйний, сильний, упевнений у собi, гордий, благородний, прямий, гiдний, ексцентричний, iнтелектуальний, вогненна, пристрасний, рiшучий, новаторський, художнiй, щедрий, вiрний, мудрий, скромний, владний, далекоглядний, вимогливий, нетерпимий, мирний, стрiмкий, що розумiє i грубий. " << endl;
        cout << " Стихiя - земля" << endl;
        cout << " Колiр - жовтий " << endl;
        break;
    }
    case 5: {
        cout << " ЗМIЯ" << endl;
        cout << " Глибокий мислитель, мудрий, мiстичний, витончений, тихий, чуттєвий, творчий, розважливий, розумний, елегантний, обережний, вiдповiдальний, спокiйний, сильний, постiйний, цiлеспрямований. Може бути одинаком, поганим спiврозмовником, притягальним, гедонiстичним, сумнiвним, недовiрливим, брехливим, задушливим i холодним. " << endl;
        cout << " Стихiя - вогонь" << endl;
        cout << " Колiр - червоний " << endl;
        break;
    }
    case 6: {
        cout << " КIНЬ" << endl;
        cout << " Веселий, популярний, кмiтливий, приземлений, сприйнятливий, балакучий, рухливий, що притягає, розумний, проникливий, гнучкий, вiдкритий. Може бути непостiйним, зарозумiлим, iнфантильним, неспокiйним, грубим, довiрливим i впертим. " << endl;
        cout << " Стихiя - вогонь" << endl;
        cout << " Колiр - червоний " << endl;
        break;
    }
    case 7: {
        cout << " ВIВЦЯ або КОЗА " << endl;
        cout << " Праведний, щирий, чуйний, лагiдний, сором'язливий, художнiй, материнськи турботливий, мирний, щедрий, що потребує безпеки. Може бути нерiшучим, надмiрно пасивним, неспокiйним, песимiстичним, занадто чутливим, скаржником i безвольним. " << endl;
        cout << " Стихiя - земля" << endl;
        cout << " Колiр - жовтий " << endl;
        break;
    }
    case 8: {
        cout << " МАВПА" << endl;
        cout << " Винахiдник, мотиватор, iмпровiзатор, меткий, допитливий, гнучкий, iнновацiйний, вирiшальний проблеми, впевнений у собi, товариський, художнiй, ввiчливий, гiдний, конкурентоздатний, об'єктивний, люблячий факти, iнтелектуальний. Може бути егоїстичними, марно зарозумiлим, егоїстичним, безрозсудним, пафосним, оманливим, манiпулятивним, хитрим, ревнивим i пiдозрiлим." << endl;
        cout << " Стихiя - метал" << endl;
        cout << " Колiр - срiблястий " << endl;
        break;
    }
    case 9: {
        cout << " ПIВЕНЬ" << endl;
        cout << " Гострий, акуратний, педантичний, органiзований, впевнений у собi, рiшучий, консервативний, критичний, перфекцiонiст, застережливий, ревнивий, практичний, науковий, вiдповiдальний. Може бути занадто ревнивим i критичним, пуританином, егоїстом, грубим, гордим, самовпевненим, хвальковитим. " << endl;
        cout << " Стихiя - метал" << endl;
        cout << " Колiр - срiблястий " << endl;
        break;
    }
    case 10: {
        cout << " СОБАКА" << endl;
        cout << " Чесний, розумний, простий, лояльний, з почуттям справедливостi i чесної гри, привабливий, дружний, невибагливий, товариський, вiдкритий, iдеалiстичний, моралiстичний, практичний, ласкавий, чутливий, спокiйний. Може бути цинiчним, ледачим, холодним, суб'єктивно оцiнюючим, песимiстичним, неспокiйним, впертим, сварливим. " << endl;
        cout << " Стихiя - земля" << endl;
        cout << " Колiр - жовтий " << endl;
        break;
    }
    case 11: {
        cout << " СВИНЯ або КАБАН або СЛОН" << endl;
        cout << " Чесний, галантний, мiцний, товариський, миролюбний, терплячий, вiдданий, працелюбний, довiрливий, щирий, спокiйний, розумiючий, вдумливий, скрупульозний, пристрасний, розумний. Може бути наївним, занадто залежним, поблажливим до себе, довiрливим, фаталiстичним, матерiалiстичним. " << endl;
        cout << " Стихiя - вода" << endl;
        cout << " Колiр - бiрюзовий " << endl;
        break;
    }
    default: {
        cout << " Щось пiшло не так ... " << endl;
        break;
    }
    }
    SetConsoleTextAttribute(color, 11);
    cout << endl << endl;
}

void endProgramText() {
    system("cls");
    system("color E1");
    cout << endl;
    cout << " ДЯКУЄМО, ЩО СКОРИСТАЛИСЯ НАШИМ ДОДАТКОМ !" << endl << endl << endl;
    cout << " Ви можете отримати персональний детальний гороскоп у нашої спадкової астрологинi Веронiки Чакри" << endl;
    cout << " Запис по star_verinica@horoscope.com" << endl;
    cout << " Приймаємо оплату у будь-якiй формi" << endl;
    cout << endl << endl << endl << endl;
    exit(0);
}
