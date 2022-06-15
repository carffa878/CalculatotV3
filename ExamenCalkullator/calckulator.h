﻿#pragma once
#include "Header.h"


/*cin - это входной поток.
cout - это выходной поток.
>> - прочитать из входного потока.
<< - записать в выходной поток
cin.peek() _ возвращает целочисленное представление следующего символа в буфере потока, не прочитав его

(cin >> a) при вводе значения a, если все нормально, то выражение вернет true, соответственно !(cin >> a) вернет false (неудачу)

cin.clear() очистит все биты и установит бит по умолчанию (std::ios_base::goodbit), таким образом приведя поток в рабочее состояние.

cin.get() считывает один символ, но нигде не хранит
 мн. ч. буфера́, бу́феры — это область памяти, используемая для временного
 хранения данных при вводе или выводе. Обмен данными (ввод и вывод) может происходить
 как с внешними устройствами, так и с процессами в пределах компьютера.

Стек — это структура данных, которая работает по принципу FILO 
(first in — last out; первый пришел — последний ушел)
stack <тип данных> <имя>;

*/
struct Leksema //Структура, описывающая любое число или операцию
{
	char type; // 0 для чисел, "+" для операции сложения вычитания  и так далее.
	double value; //Значение (только для чисел). У операций значение всегда "0"
};
bool Calculation(stack <Leksema>& Stack_number, stack <Leksema>& Stack_operation, Leksema& item)
{   // функция, которая производит расчеты  в аргумеете сылки передаеть адрес  на стек с операциями и стек с числами и на инцализатор item где храняться все сиволды
	//функция имеет тип bool, чтобы при возникновении какой-либо ошибки возвращать "false"
	double top_number_steck;              //переменая для  возражеть верхний елемент в стеке чисел
	double	next_number_steck;              //переменая для следуежево елемента стека
	double	resultat_operation;              //переменая для результатов операций
	top_number_steck = Stack_number.top().value; //Берется верхнее число из стека с числами
	Stack_number.pop(); // удаляется верхнее число из стека с числами
	switch (Stack_operation.top().type)    // операторатор switch проверяется тип верхней операции из стека с операциями
	{                                      // если тип верхней операции из стека с операциями сложение
	case '+':
		next_number_steck = Stack_number.top().value; //Stack_value.top() функция возращения верхнего елемент в стеке чисел
		Stack_number.pop();             // удаляется верхнее елемент с стека
		resultat_operation = top_number_steck + next_number_steck;     // результат операциии
		item.type = '0';             //  указиваем тип елемента а имено его тип это число ноль
		item.value = resultat_operation;    //значения результата
		Stack_number.push(item); // результат операции кладется обратно в стек с числами
		Stack_operation.pop();       // удаляется верхнее елемент с стека
		break;                      //Оператор break завершает выполнение ближайшего включающего цикла или условного оператора
	case '-':
		next_number_steck = Stack_number.top().value; //возращения верхнего елемент в стеке
		Stack_number.pop();                            // удаляется верхнее елемент с стека
		resultat_operation = next_number_steck - top_number_steck;   // результат операциии
		item.type = '0';                                            //  указиваем тип елемента а имено его тип это число ноль
		item.value = resultat_operation;                             //значения результата     
		Stack_number.push(item);                               // ложем результат  операции в стек с числами
		Stack_operation.pop();                                     // удаляется верхнее число со стека
		break;
	case '*':
		next_number_steck = Stack_number.top().value;     //возращения верхнего елемент в стеке
		Stack_number.pop();                               // удаляется верхнее елемент с стека
		resultat_operation = top_number_steck * next_number_steck;     // результат операциии
		item.type = '0';                                    //  указиваем тип елемента а имено его тип это число ноль
		item.value = resultat_operation;                   //значения результата  
		Stack_number.push(item);                      // ложем результат  операции в стек с числами
		Stack_operation.pop();                            // удаляется верхнее елемент с стека
		break;
	return true;   // возражаем true
}

