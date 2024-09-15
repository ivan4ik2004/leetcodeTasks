;implementation of the "strlen()" method in C in Assembly language

strlen:
mov es, sigment_of_string ; Загружаем в пару регистров ES:(E)DI сигмент, в котором DI будет итерироваться
push eax ; сохраняем текущее значение регистра EAX, чтобы потом вернуть
xchg eax, eax ; EAX = 0 - присваиваем 0 регистру EAX, для того чтобы искать его в строке
xchg ecx, ecx ; CX = 0 - обнуляем регистр CX
dec ecx ; ECX = ECX - 1. Получаем 0xFFFFFFF - максимальную длину строки 
cld ; бцдем двигать впёред, а не назад 
repne scasb ; ищем 0 , паралельно будет уменьшаться регистр ECX 
neg ecx ; отрицаие ECX даст количество иттераций.
pop eax ; возвращаем первоначальное значние регистра EAX
ret  ; выход из подпрограммы 


call strlen ; вызов нашей подпрограммы 


