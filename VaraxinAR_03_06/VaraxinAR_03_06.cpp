// VaraxinAR_03_06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <iostream>

int main() {
    // объявление дискрпитеров 
    HANDLE events[3];

    // запуск событий
    events[0] = CreateEventA(NULL, FALSE, FALSE, "Event1");
    events[1] = CreateEventA(NULL, FALSE, FALSE, "Event2");
    events[2] = CreateEventA(NULL, FALSE, FALSE, "Event3");
    DWORD result = WaitForMultipleObjects(3, events, FALSE, 10000);

    std::cout << "MAIN PROGRAMM" << std::endl;

    // обработка таймаута и ошибок
    if (result == WAIT_TIMEOUT) {
        std::cout << "Timeout" << std::endl;
    }
    else if (result >= WAIT_OBJECT_0 && result <= WAIT_OBJECT_0 + 2) {
        std::cout << "Event " << (result - WAIT_OBJECT_0 + 1) << " signaled" << std::endl;
    }
    else {
        std::cout << "Wait failed with error " << GetLastError() << std::endl;
    }

    // закрытие, для предотворащения утечек памяти
    CloseHandle(events[0]);
    CloseHandle(events[1]);
    CloseHandle(events[2]);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
