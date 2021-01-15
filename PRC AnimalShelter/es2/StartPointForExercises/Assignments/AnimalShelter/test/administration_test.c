#include <string.h>

#include "administration.h"
#include "unity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1,1);
}

void test_Add_Animals(void)
{
    int animalspresent = 1;
    int newanimalspresent = animalspresent;
    int maxarraylength = 20;
    ANIMAL array[maxarraylength];
    ANIMAL a1 = {animalspresent, Dog, Male, 12, {5, 6, 7}};
    int result = addAnimal(&a1, array, maxarraylength, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(a1.Id, array[animalspresent].Id);
    TEST_ASSERT_EQUAL(a1.Species, array[animalspresent].Species);
    TEST_ASSERT_EQUAL(a1.Sex, array[animalspresent].Sex);
    TEST_ASSERT_EQUAL(a1.Age, array[animalspresent].Age);
    TEST_ASSERT_EQUAL(a1.DateFound.Day, array[animalspresent].DateFound.Day);
    TEST_ASSERT_EQUAL(a1.DateFound.Month, array[animalspresent].DateFound.Month);
    TEST_ASSERT_EQUAL(a1.DateFound.Year, array[animalspresent].DateFound.Year);
}

void test_Add_Two_Animals(void)
{
    int animalspresent = 1;
    int newanimalspresent = animalspresent;
    int maxarraylength = 20;
    ANIMAL array[maxarraylength];
    ANIMAL a1 = {animalspresent, Dog, Male, 12, {5, 6, 7}};
    int result = addAnimal(&a1, array, maxarraylength, animalspresent, &newanimalspresent);
    
    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(a1.Id, array[animalspresent].Id);
    TEST_ASSERT_EQUAL(a1.Species, array[animalspresent].Species);
    TEST_ASSERT_EQUAL(a1.Sex, array[animalspresent].Sex);
    TEST_ASSERT_EQUAL(a1.Age, array[animalspresent].Age);
    TEST_ASSERT_EQUAL(a1.DateFound.Day, array[animalspresent].DateFound.Day);
    TEST_ASSERT_EQUAL(a1.DateFound.Month, array[animalspresent].DateFound.Month);
    TEST_ASSERT_EQUAL(a1.DateFound.Year, array[animalspresent].DateFound.Year);
    animalspresent++;

    ANIMAL a2 = {animalspresent, Parrot, Female, 5, {2, 5, 8}};
    result = addAnimal(&a2, array, maxarraylength, animalspresent, &newanimalspresent);

    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(a2.Id, array[animalspresent].Id);
    TEST_ASSERT_EQUAL(a2.Species, array[animalspresent].Species);
    TEST_ASSERT_EQUAL(a2.Sex, array[animalspresent].Sex);
    TEST_ASSERT_EQUAL(a2.Age, array[animalspresent].Age);
    TEST_ASSERT_EQUAL(a2.DateFound.Day, array[animalspresent].DateFound.Day);
    TEST_ASSERT_EQUAL(a2.DateFound.Month, array[animalspresent].DateFound.Month);
    TEST_ASSERT_EQUAL(a2.DateFound.Year, array[animalspresent].DateFound.Year);

    animalspresent = 21;
    ANIMAL a21 = {animalspresent, Cat, Female, 7, {1, 3, 5}};
    result = addAnimal(&a1, array, maxarraylength, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(-1, result);
}
void test_Find_Animals(void)
{
    int animalspresent = 1;
    int newanimalspresent = animalspresent;
    int maxarraylength = 20;
    ANIMAL array[maxarraylength];
    ANIMAL a1 = {animalspresent, Dog, Male, 12, {5, 6, 7}};
    addAnimal(&a1, array, maxarraylength, animalspresent, &newanimalspresent);
    animalspresent++;
    ANIMAL a2 = {animalspresent, GuineaPig, Female, 5, {2, 5, 8}};
    addAnimal(&a2, array, maxarraylength, animalspresent, &newanimalspresent);
    animalspresent++;

    int result = findAnimalById(1, array, animalspresent, &a1);
    TEST_ASSERT_EQUAL(1, result);

    result = findAnimalById(2, array, animalspresent, &a2);
    TEST_ASSERT_EQUAL(1, result);

    result = findAnimalById(3, array, animalspresent, &a1);
    TEST_ASSERT_EQUAL(0, result);

    animalspresent = 21;
    result = findAnimalById(21, array, animalspresent, &a1);
    TEST_ASSERT_EQUAL(-1, result);
}

void test_Remove_Animals(void)
{
    int animalspresent = 1;
    int newanimalspresent = animalspresent;
    int maxarraylength = 20;
    ANIMAL array[maxarraylength];
    ANIMAL a1 = {animalspresent, Dog, Male, 12, {5, 6, 7}};
    addAnimal(&a1, array, maxarraylength, animalspresent, &newanimalspresent);
    animalspresent++;
    ANIMAL a2 = {animalspresent, GuineaPig, Female, 5, {2, 5, 8}};
    addAnimal(&a2, array, maxarraylength, animalspresent, &newanimalspresent);
    animalspresent++;
    
    int result = removeAnimal(1, array, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(1, result);

    result = removeAnimal(2, array, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(1, result);

    result = removeAnimal(3, array, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(0, result);

    result = removeAnimal(21, array, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(0, result);

    result = removeAnimal(0, array, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(-1, result); 

    result = removeAnimal(-1, array, animalspresent, &newanimalspresent);
    TEST_ASSERT_EQUAL(-1, result);
} 


int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_Add_Animals);
    MY_RUN_TEST(test_Add_Two_Animals);
    MY_RUN_TEST(test_Find_Animals);
    MY_RUN_TEST(test_Remove_Animals);

    return UnityEnd();
}
