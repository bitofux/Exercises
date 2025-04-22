#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
  void *data; /*数据指针*/
  size_t element_size; /*每个元素的大小*/
  size_t size; /*顺序表的元素个数*/
  size_t capacity; /*顺序表的容量*/
}tofu_array_t;

//初始化豆腐数组
void tofu_array_init(tofu_array_t *tofu_array,size_t element_size,size_t initial_capacity ){
  tofu_array->data = malloc(element_size * initial_capacity);
  assert((tofu_array->data != NULL));
  tofu_array->element_size = element_size;
  tofu_array->size = 0;
  tofu_array->capacity = initial_capacity;
}

//释放豆腐数组
void tofu_array_free(tofu_array_t* tofu_array){
  free(tofu_array->data);
  tofu_array->data = NULL;
  tofu_array->size = 0;
  tofu_array->capacity = 0;
}

//动态扩展容量
void tofu_array_resize(tofu_array_t* tofu_array,size_t new_capacity){
  tofu_array->data = realloc(tofu_array, new_capacity);
  assert(tofu_array->data);
  tofu_array->capacity = new_capacity;
}

//尾部插入元素
void tofu_array_push(tofu_array_t *tofu_array, const void *element){
  if (tofu_array->size == tofu_array->capacity){
    tofu_array_resize(tofu_array, tofu_array->capacity * 2);/*扩展容量*/
  }
  void *target = (char*)tofu_array->data + tofu_array->size * tofu_array->element_size;
  memcpy(target,element,tofu_array->element_size); //拷贝元素
  tofu_array->size++;
}

//尾部删除元素
void tofu_array_pop(tofu_array_t *tofu_array){
  if(tofu_array->size > 0){
    tofu_array->size--;
  }
}

//设置指定索引的元素
void tofu_array_set(tofu_array_t *tofu_array,size_t index,const void *element){
  assert(0 <= index && index < tofu_array->size); //确保索引是合法的
  void *target = (char*)tofu_array->data + index * tofu_array->element_size;
  memcpy(target, element, tofu_array->element_size);
}

//获取指定索引的元素
void *tofu_array_get(tofu_array_t *tofu_array,size_t index){
  assert(0 <= index && index < tofu_array->size); //确保索引合法
  void *target = (char*)tofu_array->data + index * tofu_array->element_size;
  return target;
}

int main () {
  typedef struct {
    char *name;
    size_t id;
  }student;

  tofu_array_t tofu;
  //初始化
  tofu_array_init(&tofu, sizeof(student), 5);
  
  //插入一个整数数据
  tofu_array_push(&tofu, &(student){"wangshuai",20});

  //获取索引0的数据
  student *s1 = (student*)tofu_array_get(&tofu, 0);
  //输出s1的数据
  printf("s1->name = %s,s1->id = %lu\n",s1->name,s1->id);
}
