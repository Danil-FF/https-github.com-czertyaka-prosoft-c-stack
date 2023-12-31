# Структура данных стек

_Структура данных_ - способ хранения данных, определяющий правила добавления, поиска, изменения и удаления этих данных. Структуры в основном различают по эффективности использования памяти и алгоритмической сложности операций с данными. Простейшим примером структуры данных является
массив. Существует набор структур данных, получивший распространение в компьютерных и информационных технологиях, одним из них является стек.

_Стек_ - структура данных, основанная принципе LIFO. Расшифровка акронима LIFO (Last In First Out) относится к единице данных - последний
добавленный (last in) элемент будет первым на выдачу (first out). При последовательном добавлении нескольких элементов данных в LIFO
извлекаться они будут в порядке, обратном порядку добавления. Основанный на принципе LIFO стек определяет всего две операции для изменения
своего содержимого - это добавить элемент (традиционно операция называется `push`) и извлечь элемент (`pop`). Никаких операций для поиска и
изменения данных в "чистом" стеке не предусматривается. Рисунок ниже иллюстрирует последовательное добавление в стек и извлечение из него 5
элементов.

![image](https://github.com/czertyaka/prosoft-c-stack/assets/69390349/d2811f23-7f76-463f-81a9-a57a1066815e)

Обычно дополнительно вводят понятие _верхушки стека_. Верхушкой стека называют последний добавленный элемент стека, указатель на него или любой другой его идентификатор. Обычно именно верхушка стека является операндом `push` и `pop`, отвечающим за идентификацию самого стека. При этом в случае первой операции (добавление элемента, `push`) верхушка стека автоматически изменяется так, чтобы указывать на добавленный
элемент, а после исполнения второй операции (извлечение, `pop`) верхушка стека должна указывать на предпоследний элемент.

В подавляющем большинстве процессоров эта структура данных представлена на уровне [ISA](https://ru.wikipedia.org/wiki/%D0%90%D1%80%D1%85%D0%B8%D1%82%D0%B5%D0%BA%D1%82%D1%83%D1%80%D0%B0_%D0%BD%D0%B0%D0%B1%D0%BE%D1%80%D0%B0_%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4)
: есть команды `push`, `pop` и регистр верхушки стека (`stack pointer`, `%sp`) и их аналоги. Дело в том, что почти в каждом языке 
программирования есть функции, подпрограммы и т.д., цепочки вызовов которых очень удачно представляются в виде стека ([callstack](https://ru.wikipedia.org/wiki/%D0%A1%D1%82%D0%B5%D0%BA_%D0%B2%D1%8B%D0%B7%D0%BE%D0%B2%D0%BE%D0%B2)). В стек я́дра операционных систем
могут складывать прерывания, ядро и обычные программы - локальные переменные.
