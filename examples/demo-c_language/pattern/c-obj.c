/**
 * @description 用 c 语言实现类的继承，并且可用父类指针操作子类对像的一个测试例子
 * @see https://blog.csdn.net/tomken_zhang/article/details/6934602
 */
#include <stdio.h>   
#include <stdlib.h>
#include <string.h>
 
// 定义一个动物类，有二个方法
struct v_animal_ptr {
	const char* (*get_name)(); // 获取名字
	void (*shout)(int volume); // 喊叫
};
 
typedef struct v_animal_ptr animal_vptr;
 
// 定义函数指针
typedef const char* (*GET_NAME)();
typedef void 		(*SHOUT)(int volume);
 
// 定义一个动物类 
struct animal {
	animal_vptr *vptr;
};
 
static const char* animal_get_name(const void *class)
{
    return (*((struct animal*)class)->vptr->get_name)();
}
 
static void animal_shout(const void *class, int volume)
{
    return (*((struct animal*)class)->vptr->shout)(volume);
}
 
 
// 定义一个猪类，有一个高度值。
struct pig {
	animal_vptr *vptr;
	int    height;
};
 
static const char* pig_get_name() {
	return "i am pig";
};
 
static void pig_shout(int volume) {
	printf("heng heng %d\n", volume);
};
 
// 定义猪的实现方法
static animal_vptr pig_vptr = 
{
    (GET_NAME)	&pig_get_name,
    (SHOUT)		&pig_shout,
};
 

// 定义一个狗类，有一个颜色值。
struct dog {
	animal_vptr *vptr;
	int    color;
};
 
static const char* dog_get_name() {
	return "i am dog";
};
 
static void dog_shout(int volume) {
	printf("wang wang %d\n", volume);
};
 
static animal_vptr dog_vptr = 
{
    (GET_NAME)	&dog_get_name,
    (SHOUT)		&dog_shout,
};
 
static struct pig* init_pig() {
	struct pig* anim = (struct pig*) malloc(sizeof(struct pig));
	anim->vptr = &pig_vptr;
	anim->height = 10;
	
	return anim;
}
 
static struct dog* init_dog() {
	struct dog* anim = (struct dog*) malloc(sizeof(struct dog));
	anim->vptr = &dog_vptr;
	anim->color = 255;
	
	return anim;
}
 
int main()  
{
	struct animal *anim = NULL;
	struct pig    *pig  = NULL; 
	struct dog    *dog  = NULL;
 
	// pig 子类
	pig = init_pig();
	printf("name=%s\n", animal_get_name(pig));
	
	printf("------------------------------------\n");
	
	// dog 子类
	dog = init_dog();
	printf("name=%s\n", animal_get_name(dog));
	
	printf("------------------------------------\n");
 
	// 转向 动物父类进行操作
	anim = (struct animal *)pig;
	printf("name=%s\n", animal_get_name(anim));
	animal_shout(anim, 20);
	
	printf("------------------------------------\n");
	
	// 转向 动物父类进行操作
	anim = (struct animal *)dog;
	printf("name=%s\n", animal_get_name(anim));
	animal_shout(anim, 100);
	
    return 0;  
}