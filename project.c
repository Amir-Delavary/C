#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int year, month, day;
int CurrentYear, currentMonth, currentDay;
int answer;
int khoroji_scan;
int miladi_year, miladi_month, miladi_day;
int lMonth, lYear, lDay;
int Select;
void Back()
{
    printf("-------------------\n");
    printf("Back to menu [0]\n");
    printf("-------------------\n");
}
int past_days_found(int past_year, int past_month, int days_past)
{
    int past_days = past_year * 365.242189 + past_month * 31 + days_past;
    if (past_month > 6)
    {
        past_days -= (month - 6);
    }
    return (past_days);
}
void invaild()
{
    printf("      Invaild Input       \n");
    printf("--------------------------\n");
}
int menu()
{
    int num;
    printf("\x1b[30;47m");
    printf("           Menu           \n");
    printf("\x1b[0m"); // برگرداندن رنگ
    printf("--------------------------\n");
    printf("[0] Quit\n");
    printf("[1] Calender\n");
    printf("[2] Age\n");
    printf("[3] Conversion\n");
    printf("--------------------------\n");
    printf("Select Option: "); // مقدارگیری برای منو
    scanf("%d", &num);
    return num;
}
void miladi()
{
    miladi_year = year + 621;
    miladi_month = month + 2;
    miladi_day = day + 21;
    if (miladi_day > 30)
    {
        miladi_month += 1;
        miladi_day -= 30;
    }
    if (miladi_month > 12)
    {
        miladi_year += 1;
        miladi_month -= 12;
    }
    if (answer == 3)
    {
        printf("Miladi: %d/%d/%d\n", miladi_year, miladi_month, miladi_day);
    }
    else if (answer == 1)
    {
        printf("-------------------\n");
        printf("Miladi: %d/%d\n", miladi_year, miladi_month);
    }
}
int intPart(double value)
{
    if (value < 0)
    {
        return (int)(value - 0.5);
    }
    else
    {
        return (int)(value + 0.5);
    }
}
void ghamari()
{
    int juliandate;

    if (miladi_year > 1582 || (miladi_year == 1582 && (miladi_month > 10 || (miladi_month == 10 && miladi_day >= 15))))
    {
        juliandate = intPart((1461 * (miladi_year + 4800 + intPart((miladi_month - 14) / 12))) / 4) + intPart((367 * (miladi_month - 2 - 12 * intPart((miladi_month - 14) / 12))) / 12) - intPart((3 * intPart((miladi_year + 4900 + intPart((miladi_month - 14) / 12)) / 100)) / 4) + miladi_day - 32075;
    }
    else
    {
        juliandate = 367 * miladi_year - intPart((7 * (miladi_year + 5001 + intPart((miladi_month - 9) / 7))) / 4) + intPart((275 * miladi_month) / 9) + miladi_day + 1729777;
    }

    int l = juliandate - 1948440 + 10632;
    int n = intPart((l - 1) / 10631);

    l = l - 10631 * n + 354;

    int j = (intPart((10985 - l) / 5316)) * (intPart((50 * l) / 17719)) + (intPart(l / 5670)) * (intPart((43 * l) / 15238));

    l = l - (intPart((30 - j) / 15)) * (intPart((17719 * j) / 50)) - (intPart(j / 16)) * (intPart((15238 * j) / 43)) + 29;
    lMonth = intPart((24 * l) / 709);
    lDay = l - intPart((709 * lMonth) / 24);
    lYear = 30 * n + j - 30;
    if (answer == 3)
    {
        printf("Ghamari: %d, %d, %d\n", lYear, lMonth, lDay);
    }
    if (answer == 1)
    {
        printf("Ghamari: %d/%d\n", lYear, lMonth);
    }
}
void Conversion_menu()
{
    printf("[1] Solar\n");
    printf("[2] AD\n");
    printf("--------------------------\n");
    printf("Select Option: ");
    scanf("%d", &Select);
    system("cls");
}
int scan()
{
    if (answer == 3)
    {
        Conversion_menu();
        if (Select == 0)
        {
            return 0;
        }
        else if (Select >= 3)
        {
            invaild();
            return 0;
        }
    }
    if (answer == 2)
    {
        printf("Enter Year: ");
        scanf("%d", &year);
        while (year >= CurrentYear)
        {
            printf("\033[F\033[K");
            printf("Enter Year: ");
            scanf("%d", &year);
        }
        if (year == 0)
        {
            system("cls");
            return 0; // again run
        }
    }
    else
    {
        printf("Enter Year: ");
        scanf("%d", &year);
        if (year == 0)
        {
            system("cls");
            return 0; // again run
        }
    }

    printf("Enter Month: ");
    scanf("%d", &month);
    while (month > 12)
    {
        printf("\033[F\033[K");
        printf("Enter Month: ");
        scanf("%d", &month);
    }
    if (month == 0)
    {
        system("cls");
        return 0; // again run
    }

    if (answer == 2 || answer == 3)
    {
        printf("Enter Day: ");
        scanf("%d", &day);
        while (day > 31)
        {
            printf("\033[F\033[K");
            printf("Enter Day: ");
            scanf("%d", &day);
        }
        if (day == 0)
        {
            system("cls");
            return 0;
        }
    }
    return 1;
}
void Calender()
{
    int start_day;
    int past_days = 0;                                                    // روز های گذشته شده
    int lenght;                                                           // برای تعداد حرف های هر کلمه
    int day_month[12] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29}; // تعداد روز های هر ماه
    past_days = past_days_found(year - 1, month - 1, 0);
    char *months[] = {
        "farvardin",
        "ordibehesht",
        "khordad",
        "tir",
        "mordad",
        "shahrivar",
        "mehr",
        "aban",
        "azar",
        "dey",
        "bahman",
        "esfand"};
    int adad_mah;
    switch (month)
    {
    case 1:
        lenght = strlen(months[0]);
        adad_mah = 1;
        break;
    case 2:
        lenght = strlen(months[1]);
        adad_mah = 2;
        break;
    case 3:
        lenght = strlen(months[2]);
        adad_mah = 3;
        break;
    case 4:
        lenght = strlen(months[3]);
        adad_mah = 4;
        break;
    case 5:
        lenght = strlen(months[4]);
        adad_mah = 5;
        break;
    case 6:
        lenght = strlen(months[5]);
        adad_mah = 6;
        break;
    case 7:
        lenght = strlen(months[6]);
        adad_mah = 7;
        break;
    case 8:
        lenght = strlen(months[7]);
        adad_mah = 8;
        break;
    case 9:
        lenght = strlen(months[8]);
        adad_mah = 9;
        break;
    case 10:
        lenght = strlen(months[9]);
        adad_mah = 10;
        break;
    case 11:
        lenght = strlen(months[10]);
        adad_mah = 11;
        break;
    case 12:
        lenght = strlen(months[11]);
        adad_mah = 12;
        break;
    }
    int fist_space = (26 - lenght) / 2;
    int lim_f_space = 1;
    int end_space = 0;
    printf("\x1b[30;47m");
    for (; lim_f_space <= fist_space; lim_f_space++)
    {
        printf(" ");
    }
    printf("%s", months[adad_mah - 1]);
    for (; end_space + lim_f_space + lenght != 27; end_space++)
    {
        printf(" ");
    }
    printf("\n");
    printf("\x1b[0m"); // برگرداندن رنگ
    printf("Sa  Su  Mo  Tu  We  Th  Fr\n");
    start_day = (past_days) % 7; // برای این با 6 جمع شده است چرا که تقویم اولین سال شمسی از جمعه شروع میشود
    int i = 1;
    for (; i <= start_day; i++)
    {
        printf("    ");
    }
    for (int day = 1; day <= day_month[month - 1]; day++, i++)
    {
        printf("%2d  ", day);
        if (i % 7 == 0)
        {
            printf("\n"); // بعد از اینکه در هر سطر 7 مقدار چاپ شد به سطر بعدی برود
        }
    }
    printf("\n");
    miladi();
    ghamari();
}
void age()
{
    int year_age = CurrentYear - year;
    int month_age = currentMonth - month;
    int day_age = currentDay - day;
    int life_days;
    if (month_age < 0)
    {
        month_age += 12;
        year_age -= 1;
    }
    if (day_age < 0)
    {
        day_age += 30;
        month_age -= 1;
    }
    printf("you born in: ");
    int find_day = past_days_found(year, month, day);
    switch ((find_day + 1) % 7)
    {
    case 0:
        printf("shanbe\n");
        break;
    case 1:
        printf("yekshanbe\n");
        break;
    case 2:
        printf("doshanbe\n");
        break;
    case 3:
        printf("seshanbe\n");
        break;
    case 4:
        printf("charshanbe\n");
        break;
    case 5:
        printf("panjshanbe\n");
        break;
    case 6:
        printf("jome\n");
        break;
    }
    life_days = past_days_found(year_age, month_age, day_age);
    printf("Age: %d years,%d month,%d days\n\n", year_age, month_age, day_age);
    printf("Your date of birth in AD: %d/%d/%d\n", miladi_year, miladi_month, miladi_day);
    printf("Your date of birth in the Solar date: %d/%d/%d\n", year, month, day);
    printf("Your date of birth in the lunar date: %d/%d/%d\n\n", lYear, lMonth, lDay);
    printf("The number of past days of your life: %d\n", life_days);
}
void convert_from_Solar()
{
    year -= 621;
    month -= 2;
    day -= 21;
    if (month <= 0)
    {
        year -= 1;
        month += 12;
    }
    if (day <= 0)
    {
        if (month <= 6)
        {
            day += 31;
        }
        else
        {
            day += 30;
        }
        month -= 1;
    }
    if (month <= 0)
    {
        year -= 1;
        month += 12;
    }
    printf("Shamsi: %d/%d/%d\n", year, month, day);
}
void menu_run()
{
    while (month <= 12 && year != 0) // برای اینکه بعد از چاپ توابع خواسته شده مجددا ورودی بگیرد
    {
        system("cls");
        if (answer == 1)
        {
            Calender(); // چاپ تقویم
        }
        else if (answer == 2)
        {
            miladi();
            ghamari();
            age(); // محاسبه سن
        }
        else if (Select == 1)
        {
            miladi(); // محاسبه تاریخ میلادی
            ghamari();
        }
        else if (Select == 2)
        {
            convert_from_Solar();
            miladi();
            ghamari();
        }

        Back();
        khoroji_scan = scan(); // برای گرفتن مجدد ورودی
        if (khoroji_scan == 0)
        {
            break;
        }
    }
}
int main()
{
    printf("current year: "); // برای گرفتن تاریخ حال
    scanf("%d", &CurrentYear);
    printf("current month: ");
    scanf("%d", &currentMonth);
    printf("current day: ");
    scanf("%d", &currentDay);
    system("cls");
    answer = menu(); // run menu
    while (answer != 0)
    {
        if (answer == 1 || answer == 2 || answer == 3)
        {
            system("cls"); // delete all printed
            Back();
            khoroji_scan = scan();
            while (1) // علت استفاده از چرخه این است که اگر خروجی اسکن 1 بود مجدد تابع را اجرا کند
            {
                if (khoroji_scan == 0)
                {
                    break; // چرخه و شرط را میبندد و مجدد برای Answer ورودی میگیرد
                }
                else if (khoroji_scan == 1)
                {
                    menu_run(); // در انتهای این تابع مجددا برای بخش اجرا شده ورودی میگیرد
                }
            }
        }
        else
        {
            system("cls");
            invaild();
        }
        answer = menu();
    }
    system("cls");
    printf("Bye!");
    exit(0); // exit
}
