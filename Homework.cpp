#include <iostream>
#include <cmath>

//Task1
void gettingTrapezoidArea() {
    int b1, b2, h;
    std::cout << "Enter 2 bases and height: " << std::endl;
    std::cin >> b1 >> b2 >> h;
    std::cout << "square = " << ((b1 + b2) / 2 * h);
    std::cout << std::endl;
}

//Task 2
void gettingCircumferenceAndAreaOfCircle() {
    int r;
    double p = 3.14;
    std::cout << "Enter the radius: " << std::endl;
    std::cin >> r;
    std::cout << "Circle length = " << (2 * p * r) << ", " << "Circumference square = " << (p * r * r);
    std::cout << std::endl;
}

//Task 3
void gettingAreaAndHypotenuseOfTriangle() {
    int a, b;
    double c;
    std::cout << "Enter the lengths of the cathets: " << std::endl;
    std::cin >> a >> b;
    std::cout << "The area of the triangle = " << a * b / 2 << ", " << "Hypotenuse = " << sqrt(pow(a, 2) + pow(b, 2));
    std::cout << std::endl;
}

//Task 4
void gettingSumOfDigits() {
    int chislo, summa;
    std::cout << "Enter the number: " << std::endl;
    std::cin >> chislo;
    int number1 = chislo / 1000;
    int number2 = chislo % 1000 / 100;
    int number3 = chislo % 100 / 10;
    int number4 = chislo % 10;
    summa = number1 + number2 + number3 + number4;
    std::cout << "Sum of digits = " << summa;
    std::cout << std::endl;
}

//Task 5
struct PolarCoordinates {
    double r; // радиус
    double theta; // угол в радианах
};

struct CartesianCoordinates {
    double x; // координата по оси X
    double y; // координата по оси Y
};

PolarCoordinates convertToPolar(const CartesianCoordinates& cartesian) {
    PolarCoordinates polar;
    polar.r = sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y); // вычисляем радиус
    polar.theta = atan2(cartesian.y, cartesian.x); // вычисляем угол
    return polar;
}

void coordinatesConvertToPolar() {
    std::cout << "15. Конвертация из декартовых в полярные координаты. Пример ввода 1,1; ответ '1.41, 0.78' " << std::endl;
    CartesianCoordinates cartesian;
    std::cout << "Введите координату X: ";
    std::cin >> cartesian.x;
    std::cout << "Введите координату Y: ";
    std::cin >> cartesian.y;

    PolarCoordinates polar = convertToPolar(cartesian);

    std::cout << "Полярные координаты: ";
    std::cout << "Радиус: " << polar.r << std::endl;
    std::cout << "Угол: " << polar.theta << " радиан" << std::endl;
}

//Task 6 inludes structures from task 5
CartesianCoordinates convertToCartesian(const PolarCoordinates& polar) {
    CartesianCoordinates cartesian;
    cartesian.x = polar.r * cos(polar.theta); // вычисляем координату X
    cartesian.y = polar.r * sin(polar.theta); // вычисляем координату Y
    return cartesian;
}

void coordinatesConvertToCartesian() {
    std::cout << "15. Конвертация из полярных в декартов координаты. Пример ввода 1,1; ответ '0.54, 0.84' " << std::endl;
    PolarCoordinates polar;
    std::cout << "Введите радиус: ";
    std::cin >> polar.r;
    std::cout << "Введите угол (в радианах): ";
    std::cin >> polar.theta;

    CartesianCoordinates cartesian = convertToCartesian(polar);

    std::cout << "Декартовы координаты: ";
    std::cout << "X: " << cartesian.x << std::endl;
    std::cout << "Y: " << cartesian.y << std::endl;
}

//Task 7
void findRoots() {
    std::cout << "7.Нахождение корней, тестовый ввод 2x^2+2x+2=0 где a=2,b=2,c=2, ответ 'Корней нет' " << std::endl;

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    std::cout << "Квадратное уравнение имеет вид: ax^2+bx+c=0" << std::endl;
    std::cout << "Введите a" << std::endl;
    std::cin >> a;
    std::cout << "Введите b" << std::endl;
    std::cin >> b;
    std::cout << "Введите c" << std::endl;
    std::cin >> c;

    // Кейс полного
    if (a != 0 && b != 0 && c != 0) {
        double discriminant = 0.0;
        discriminant = b * b - 4 * a * c;
        if (discriminant > 0)
            std::cout << "X1= " << (-b - pow(discriminant, 0.5)) / (2 * a) << " X2= " << (-b + pow(discriminant, 0.5)) / (2 * a) << std::endl;
        else if (discriminant == 0)
            std::cout << "X1,X2 = " << -b / (2 * a) << std::endl;
        else
            std::cout << "Корней нет" << std::endl;
    }
    else if (a == 0) {
        if (b == 0 || c == 0)
            std::cout << "Некорректный ввод" << std::endl;
        else
            std::cout << "X= " << -c / b << std::endl;
    }
    else if (b == 0) {
        if (c == 0)
            std::cout << "X=0" << std::endl;
        else if (c < 0)
            std::cout << "X= " << pow(-c / a, 0.5) << std::endl;
        else
            std::cout << "Корней нет " << std::endl;
    }
    else if (c == 0) {
        if (a == 0 || b == 0)
            std::cout << "Некорректный ввод" << std::endl;
        else std::cout << "X1 = 0, X2 = " << -b / a << std::endl;
    }
    else
        std::cout << "Что-то не так" << std::endl;
}

//Task 8
double findSideMedian(double main_side, double side2, double side3) {
    return 0.5 * pow(2 * pow(side2, 2) + 2 * pow(side3, 2) - pow(main_side, 2), 0.5);
}

bool checkTriangle(double a, double b, double c) {
    if (a > b + c || b > a + c || c > b + c) {
        std::cout << "Невозможно создать треугольник" << std::endl;
        return false;
    }
    return true;
}

void findMedians() {

    std::cout << "8.Нахождение медиан треугольника из медиан изначального треугольника: Тестовый ввод a=3,b=3,c=3. Ответ 2.25 (3 раза)" << std::endl;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "Введите стороны a,b и c:" << std::endl;
    std::cin >> a >> b >> c;
    if (checkTriangle(a, b, c)) {
        double ma = findSideMedian(a, b, c);
        double mb = findSideMedian(b, c, c);
        double mc = findSideMedian(c, b, a);

        if (checkTriangle(ma, mb, mc)) {
            double ma2 = findSideMedian(ma, mb, mc);
            double mb2 = findSideMedian(mb, mc, mc);
            double mc2 = findSideMedian(mc, mb, ma);
            std::cout << ma2 << " " << mb2 << " " << mc2 << std::endl;
        }
    }
}

//Task 9
void calcMinutesAndHours() {
    std::cout << "9. Расчет перевод секунд в целые минуты или целые часы, пример ввода k = 3651, ответ 1 и 1" << std::endl;
    int k = 0;
    std::cout << "Ввведите целочисленную секунду: " << std::endl;
    std::cin >> k;

    int minits = k / 60;
    int hours = minits / 60;
    minits -= hours * 60;
    if (k >= 0)
        std::cout << "Целых минут: " << minits << " и целых часов: " << hours << std::endl;
    else
        std::cout << "Секунда должна быть больше 0" << std::endl;
}

//Task 10
void isTriangleIsosceles() {
    std::cout << "10. Проверка треугольника на равнобедренность, пример ввода a=5,b=5,c=2, ответ да" << std::endl;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    std::cout << "Введите стороны a,b и c:" << std::endl;
    std::cin >> a >> b >> c;

    if (a == b || b == c || a == c)
        std::cout << "Треугольник равнобедренный" << std::endl;
    else
        std::cout << "Треугольник не равнобедренный" << std::endl;
}

//Task 11
void gettingPurchasePrice() {
    int cost;
    std::cout << "Enter the cost: " << std::endl;
    std::cin >> cost;
    if (cost > 1000) {
        std::cout << "Cost = " << cost / 100 * 90;
    }
    else {
        std::cout << "Cost = " << cost;
    }
    std::cout << std::endl;
}

//Task 12
void gettingWeightRecommendations() {
    int height, weight;
    std::cout << "Enter height and weight: " << std::endl;
    std::cin >> height >> weight;
    if (height - 100 > weight) {
        std::cout << "You need to get better.";
    }
    else if (height - 100 < weight) {
        std::cout << "You need to lose weight.";
    }
    else {
        std::cout << "You have the ideal weight.";
    }
    std::cout << std::endl;
}

//Task 13
#include <cstdlib>
#include <ctime>

void gettingRandomMultiplication() {
    std::cout << "13. Генерация рандомного числа и тест, пример генерации 2,3 ввод 6, ответ 'неправильно'" << std::endl;
    // Установка генератора случайных чисел
    std::srand(static_cast<unsigned int>
        (std::time(nullptr)));

    // Генерация двух случайных чисел в диапазоне от 1 до 9
    int num1 = std::rand() % 9 + 1;
    int num2 = std::rand() % 9 + 1;

    // Вычисление произведения этих чисел
    int result = num1 * num2;

    // Вывод задания на экран
    std::cout << "Умножьте " << num1 << " на " << num2 << ": ";

    // Чтение ответа пользователя
    int userAnswer;
    std::cin >> userAnswer;

    // Проверка ответа
    if (userAnswer == result) {
        std::cout << "Правильно! Ответ " << result << std::endl;
    }
    else {
        std::cout << "Неправильно. Правильный ответ: " << result << std::endl;
    }

}

//Task 14
void getNegotiationCost() {
    std::cout << "14. Расчет стоимости переговоров (стоимость 1 минуты разговора 0.5 рубля). Пример ввода 10,7; ответ '4' " << std::endl;
    // Ввод продолжительности разговора
    int duration;
    std::cout << "Введите продолжительность  в минутах: ";
    std::cin >> duration;

    // Ввод дня недели
    int day;
    std::cout << "Введите день недели (число от 1 до 7, где 1 - понедельник): ";
    std::cin >> day;

    // Расчет стоимости без учета скидки
    double cost = duration * 0.5; // Предполагаем, что стоимость 1 минуты разговора 0.5 рубля

    // Проверка на выходные дни (субботу и воскресенье)
    if (day == 6 || day == 7) {
        // Расчет стоимости с учетом скидки 20%
        cost *= 0.8;
    }

    // Вывод стоимости переговоров
    std::cout << "Стоимость переговоров: " << cost << " рублей" << std::endl;
}

//Task 15
void gettingMonthAndSeason() {
    int month;
    std::cout << "Enter the month number: " << std::endl;
    std::cin >> month;

    switch (month)
    {
    case 1:
        std::cout << "January, winter" << "\n";
        break;
    case 2:
        std::cout << "February, winter" << "\n";
        break;
    case 3:
        std::cout << "March, spring" << "\n";
        break;
    case 4:
        std::cout << "April, spring" << "\n";
        break;
    case 5:
        std::cout << "May, spring" << "\n";
        break;
    case 6:
        std::cout << "June, summer" << "\n";
        break;
    case 7:
        std::cout << "July, summer" << "\n";
        break;
    case 8:
        std::cout << "August, summer" << "\n";
        break;
    case 9:
        std::cout << "September, autumn" << "\n";
        break;
    case 10:
        std::cout << "October, autumn" << "\n";
        break;
    case 11:
        std::cout << "November, autumn" << "\n";
        break;
    case 12:
        std::cout << "December, winter" << "\n";
        break;
    default:
        std::cout << "The month is entered incorrectly." << "\n";
        break;
    }
    std::cout << std::endl;
}

//Task 16
void isHappyNumber() {
    std::cout << "16. Проверка шестизначного числа на счастливость. Пример ввода 123114; ответ 'да, является' " << std::endl;
    // Ввод шестизначного числа
    int number;
    std::cout << "Введите шестизначное число: ";
    std::cin >> number;

    // Проверка, является ли число шестизначным
    if (number >= 100000 && number <= 999999) {
        // Разделение числа на три пары цифр
        int firstPart = number / 1000; // Первые три цифры
        int secondPart = number % 1000; // Последние три цифры

        // Вычисление суммы цифр каждой пары
        int sumFirstPart = 0;
        while (firstPart > 0) {
            sumFirstPart += firstPart % 10; // Получаем последнюю цифру и добавляем ее к сумме
            firstPart /= 10; // Удаляем последнюю цифру
        }

        int sumSecondPart = 0;
        while (secondPart > 0) {
            sumSecondPart += secondPart % 10; // Получаем последнюю цифру и добавляем ее к сумме
            secondPart /= 10; // Удаляем последнюю цифру
        }

        // Проверка, является ли число "счастливым"
        if (sumFirstPart == sumSecondPart) {
            std::cout << "Число является 'счастливым'!" << std::endl;
        }
        else {
            std::cout << "Число не является 'счастливым'." << std::endl;
        }
    }
    else {
        std::cout << "Ошибка! Число не является шестизначным." << std::endl;
    }

}

//Task 17.
void getPennyString() {
    std::cout << "17. Склонение копейки, пример, 11 - Копеек " << std::endl;
    int penny = 0;
    std::cout << "Введите число для копейки: ";
    std::cin >> penny;

    if (penny <= 10) {
        if (penny == 1)
            std::cout << "Копейка" << std::endl;
        else if (penny > 1 && penny <= 4)
            std::cout << "Копейки" << std::endl;
        else
            std::cout << "Копеек" << std::endl;
    }
    else if (penny >= 11 && penny <= 20) {
        std::cout << "Копеек" << std::endl;
    }
    else {
        if (penny % 10 == 1)
            std::cout << "Копейка" << std::endl;
        else if (penny % 10 > 1 && penny % 10 <= 4)
            std::cout << "Копейки" << std::endl;
        else
            std::cout << "Копеек" << std::endl;
    }
}

//Task 18
bool isPalindrome(int number) {
    int reverseNumber = 0;
    int temp = number;

    // переворачиваем число
    while (temp > 0) {
        reverseNumber = reverseNumber * 10 + temp % 10;
        temp /= 10;
    }

    // проверяем, является ли число палиндромом
    if (reverseNumber == number)
        return true;
    else
        return false;
}

void findPalindrome() {
    std::cout << "18. Проверка четерыхзначного числа на палиндром. Пример ввода 2552; ответ 'нет, да' " << std::endl;

    int number;
    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;

    if (isPalindrome(number))
        std::cout << "Число является палиндромом." << std::endl;
    else
        std::cout << "Число не является палиндромом." << std::endl;

}

//Task 19.
void numberCheck() {
    std::cout << "19. Операции с цифрами числа. Пример ввода 322, 13; ответ 'нет, да' " << std::endl;

    int number = 0;
    int dublicate = 0;
    std::cout << "Введите трехзначное число: " << std::endl;
    std::cin >> number;
    if (number >= 999 || number < 100) {
        std::cout << "Ошибка, некорректное число: " << std::endl;
        return;
    }
    int b = 0;
    std::cout << "Введите число b: " << std::endl;
    std::cin >> b;

    //19.1
    dublicate = number;
    int Product = 1;
    for (int i = 100; i >= 1; i = i / 10)
    {
        int digit = (dublicate / i) % 10;
        Product *= digit;
    }

    if (Product > b)
        std::cout << Product << " (Произведение) > b==" << b << ", да" << std::endl;
    else
        std::cout << Product << " (Произведение) <= b==" << b << ", нет" << std::endl;

    //19.2
    dublicate = number;
    int sum = 0;
    for (int i = 100; i >= 1; i = i / 10)
    {
        int digit = (dublicate / i) % 10;
        sum += digit;
    }

    if (sum % 7 == 0)
        std::cout << "Сумма цифр кратна 7, да" << std::endl;
    else
        std::cout << "Сумма цифр не кратна 7, нет" << std::endl;
}

//Task 20.
void rektangelCheck() {
    std::cout << "20. Проверка на возможность вписать прямоугольник. Тестовый ввод a=11,b=20,c=5,d=10; Ответ для него 'нет' " << std::endl;

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    std::cout << "Введите стороны a,b (вписываемого прямоугольника):" << std::endl;
    std::cin >> a >> b;
    std::cout << "Введите стороны c,d (второго прямоугольника):" << std::endl;
    std::cin >> c >> d;

    if (((a < c) && (b < d)) || ((a < d) && (b < c)))
        std::cout << "Можно вписать, да" << std::endl;
    else
        std::cout << "Нельзя вписать, нет" << std::endl;
}

//Task 21
void printTypeSizes() {
    std::cout << "Размеры основных типов данных в байтах:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Тип int: " << sizeof(int) << " байт" << std::endl;
    std::cout << "Тип short: " << sizeof(short) << " байт" << std::endl;
    std::cout << "Тип long: " << sizeof(long) << " байт" << std::endl;
    std::cout << "Тип long long: " << sizeof(long long) << " байт" << std::endl;
    std::cout << "Тип float: " << sizeof(float) << " байт" << std::endl;
    std::cout << "Тип double: " << sizeof(double) << " байт" << std::endl;
    std::cout << "Тип char: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Тип bool: " << sizeof(bool) << " байт" << std::endl;
    //Размер типа char обычно составляет 1 байт и используется для представления одного символа. Размер типа bool также обычно составляет 1 байт и используется для представления логических значений true и false.
}

int main()
{
    setlocale(LC_ALL, "Russian");

    gettingTrapezoidArea(); //1
    gettingCircumferenceAndAreaOfCircle(); //2
    gettingAreaAndHypotenuseOfTriangle(); //3
    gettingSumOfDigits(); //4
    coordinatesConvertToPolar(); //5
    coordinatesConvertToCartesian(); //6
    findRoots(); //7
    findMedians(); //8
    calcMinutesAndHours(); //9
    isTriangleIsosceles(); //10
    gettingPurchasePrice(); //11
    gettingWeightRecommendations(); //12
    gettingRandomMultiplication(); //13
    getNegotiationCost(); //14
    gettingMonthAndSeason(); //15
    isHappyNumber(); // 16
    getPennyString(); //17
    findPalindrome(); //18
    numberCheck(); //19
    rektangelCheck(); //20
    printTypeSizes(); //21

}
