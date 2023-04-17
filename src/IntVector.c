#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *vector = (IntVector*)malloc(sizeof(IntVector));
    if (!vector) {
        free(vector);
        return NULL;
    }

    vector->capacity = initial_capacity;
    int *data = (int*) malloc(sizeof(int) * initial_capacity);
    if (!data) {
        free(vector);
        return NULL;
    }
    vector->size = 0;
    vector->data = data;
    return vector;
}

IntVector *int_vector_copy(const IntVector *v)//Указатель на копию вектора
{
    IntVector *copy_vec =  malloc(sizeof(IntVector));
    if(copy_vec == NULL)
    {
        free(copy_vec);
        return NULL;
    }
    copy_vec->data = malloc(v->capacity * sizeof(int)); 
    if(copy_vec->data == NULL )
    {
        free(copy_vec->data);
        return NULL;
    }
    memcpy(copy_vec->data, v->data, sizeof(int) * v->capacity);
    copy_vec->capacity = v->capacity;
    copy_vec->size = v->size;
    return copy_vec;
}

void int_vector_free(IntVector *v)//Освобождает память, выделенную для вектора
{   
    if (v){
        free(v->data);
        free(v);
    {
}

int int_vector_get_item(const IntVector *v, size_t index)//возвращает элемент под номером index
{
    return v->data[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item)// Присваивает элементу под номером index значение item
{
    if(index <= v->size){
        v->data[index] = item;
    }
}

size_t int_vector_get_size(const IntVector *v)// размер вектора.
{
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)// емкость вектора
{
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)//Добавляет элемент в конец массива
{
    if(v->size >= v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data,sizeof(int) * v->capacity);
        if(v->data == NULL )
        {
           free(v);
           return -1;
        }
    }
    v->data[v->size] = item;
    v->size++;
    return 0;
}

void int_vector_pop_back(IntVector *v)//Удаляет последний элемент из массива
{
    if(v->size != 0)
    {
        v->size--;
    }
}

int int_vector_shrink_to_fit(IntVector *v)//Уменьшает емкость массива до его размера.
{
    if(v->size > v->capacity)
    {
        return -1;
    }

    v->capacity = v->size;
    v->data = realloc(v->data,sizeof(int) * v->capacity);
    if(v->data == NULL )
    {
        free(v);
       return -1;
    }

    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)//Изменить размер массива.
{
    if (v->capacity < new_size) {
        if (int_vector_reserve(v, new_size)) {
            return -1;
        }
        for (int i = v->size; i < new_size; i++) {
            (v->data)[i] = 0;
        }
    }
    v->size = new_size;
    return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)//Изменить емкость массива.
{
    if(new_capacity <= v->capacity)
    {
        return -1;
    }
    v->capacity = new_capacity;
    v->data = realloc(v->data,sizeof(int) * v->capacity);
    if(!v->data)
    {
        return -1;
    }
    return 0;
}
