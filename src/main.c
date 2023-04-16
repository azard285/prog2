#include <stdio.h>
#include "IntVector.h"

void printVector(IntVector *vec1) {
	printf("elements of array: ");
	for (int i = 0; i < vec1->size; i++) {
		printf("%d ", vec1->data[i]);
	}
	printf("\n");
}

int main()
{
    IntVector *vec1 = int_vector_new(10);
    vec1->size = 4;
	vec1->data[0] = 1;
    vec1->data[1] = 2;
    vec1->data[2] = 3;
    vec1->data[3] = 4;

    printf("\nint_vector_new\n");
    printf("Первый вектор, созданный с помощью int_vector_new \n");
    printVector(vec1);
    
    printf("\nint_vector_copy\n");
    printf("\nКопируем Второй вектор в Первый\n");
    IntVector *a = int_vector_copy(vec1);

    printf("Первый вектор\n");
    printVector(vec1);
    printf("Второй вектор\n");
    printVector(a);
	
    printf("\nint_vector_free. Очистим первый вектор.\n"); 
    int_vector_free(vec1);
    printf("Второй вектор\n");
    printVector(a);

    printf("\nint_vector_get_item.\n");
    printf("Index %d: %d\n",3,int_vector_get_item(a, 3));

    printf("\nint_vector_set_item. Заменим второй индекс на значение 1\n");
    int_vector_set_item(a, 2, 1);
    printVector(a);

    printf("\nint_vector_get_size\n");
    printf("Size: %ld\n",int_vector_get_size(a));

    printf("\nint_vector_get_capacity\n");
    printf("Capacity: %ld\n",int_vector_get_capacity(a));

    printf("\nint_vector_push_back. Добавим в конец значение 2\n"); 
    int_vector_push_back(a, 2);
    printVector(a);

    printf("\nint_vector_pop_back. Удалим посдеднюю двойку\n"); 
    int_vector_pop_back(a);
    printVector(a);

    printf("\nint_vector_shrink_to_fit. Уменьшает емкость массива до его размера\n"); 
    int_vector_shrink_to_fit(a);
    printVector(a);

    printf("\nint_vector_resize. Изменим размер массива на 11\n"); 
    int_vector_resize(a, 11);
    printVector(a);

    printf("\nint_vector_reserve. Изменим емкость массива на 20\n"); 
    int_vector_reserve(a,20);
    printVector(a);
    
    int_vector_free(a);
    return 0;
}