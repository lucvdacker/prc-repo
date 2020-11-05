#include "administration.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Note: make sure to set 'resource_detector.h' as the last include.
#include "resource_detector.h"


int addAnimal(
            const Animal* animalPtr, Animal* animalArray,
            size_t animalArrayLength, size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent, int animalId)
{
    for (int i = 0; i < numberOfAnimalsPresent; i++)
    {
        if (animalArray[i].Id == animalId)
        {
            for (int j = i; j < numberOfAnimalsPresent; j++)
            {
                animalArray[j] = animalArray[j + 1];
            }

            numberOfAnimalsPresent++;
        }
    }
    *newNumberOfAnimalsPresent = numberOfAnimalsPresent;
    if (numberOfAnimalsPresent == *newNumberOfAnimalsPresent)
    {
        return 1;
    }
    return 0;
}

int removeAnimal(
            int animalId, Animal* animalArray,
            size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    for (int i = 0; i < numberOfAnimalsPresent; i++)
    {
        if (animalArray[i].Id == animalId)
        {
            for (int j = i; j < numberOfAnimalsPresent; j++)
            {
                animalArray[j] = animalArray[j + 1];
            }

            numberOfAnimalsPresent--;
        }
    }
    *newNumberOfAnimalsPresent = numberOfAnimalsPresent;
    if (numberOfAnimalsPresent == *newNumberOfAnimalsPresent)
    {
        return -1;
    }
    return 0;
}

int findAnimalById(
            int animalId, const Animal* animalArray,
            size_t numberOfAnimalsPresent, Animal* animalPtr)
{
    for (int i = 0; i < numberOfAnimalsPresent; i++)
    {
        if (animalArray[i].Id == animalId)
        {
            return animalId;
        }
    }

}

/*-------------------------------------------------------------------------------*/
int sortAnimalsByAge(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    int *age;
   for (age = 1; age < animalArray; ++age) {                   

      for (size_t i = 0; i < animalArray - 1; ++i) {                     

         if (animalArray[i] > animalArray[i + 1]) {                        
            int keep = animalArray[i];                               
            animalArray[i] = animalArray[i + 1];                             
            animalArray[i + 1] = keep;                               
         }                                       
      }                                   
   }                                      

    
}

int sortAnimalsByYearFound(
            Animal* animalArray, size_t numberOfAnimalsPresent)
{
    int *yearFound;
   for (yearFound = 1; yearFound < animalArray; ++yearFound) 
   {                
      for (size_t i = 0; i < animalArray - 1; ++i) 
      {                     
         if (animalArray[i] > animalArray[i + 1]) {                        
            int keep = animalArray[i];                               
            animalArray[i] = animalArray[i + 1];                             
            animalArray[i + 1] = keep;                               
         }                                       
      }                                   
   } 
}

int sortAnimalsBySex(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    return 0;
}
