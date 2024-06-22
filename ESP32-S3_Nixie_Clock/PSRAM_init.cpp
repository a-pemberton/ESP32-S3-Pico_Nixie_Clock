
#include "ESP32_Nixie.h"

// Allocate global pointers to PSRAM display memory
extern uint16_t *dispImageNum_0;
extern uint16_t *dispImageNum_1;
extern uint16_t *dispImageNum_2;
extern uint16_t *dispImageNum_3;
extern uint16_t *dispImageNum_4;
extern uint16_t *dispImageNum_5;
extern uint16_t *dispImageNum_6;
extern uint16_t *dispImageNum_7;
extern uint16_t *dispImageNum_8;
extern uint16_t *dispImageNum_9;

extern uint16_t **digit_MemoryImages[]; // = {&dispImageNum_0,&dispImageNum_1,&dispImageNum_2,&dispImageNum_3,&dispImageNum_4,&dispImageNum_5,&dispImageNum_6,&dispImageNum_7,&dispImageNum_8,&dispImageNum_9};
extern const uint16_t *Image_Names[]; // = {Num0_New,Num1_New,Num2_New,Num3_New,Num4_New,Num5_New,Num6_New,Num7_New,Num8_New,Num9_New};

bool setup_PSRAM_Init(void);
bool setup_PSRAM_Images(void);

bool setup_PSRAM_Init(void)
{
  uint16_t *p_psram;
  if (psramInit())
  {
#ifdef DEBUG_PSRAM
    Serial.println("\nPSRAM is correctly initialized");
    printMem();
    Serial.printf("Initial Used PSRAM: %d\n", ESP.getPsramSize() - ESP.getFreePsram());
#endif
  }
  else
  {
#ifdef DEBUG_PSRAM
    Serial.println("PSRAM not available");
#endif
    return true;
  }
  return false;
}

bool setup_PSRAM_Images(void)
{

// Print unallocted address table
#ifdef DEBUG_PSRAM
  Serial.println("Using PSRAM malloc for 10 Image_Size blocks");
#endif

  for (int n = 0; n < 10; n++)
  {

//    p_psram = (uint16_t *)ps_malloc(Image_Size * sizeof(uint16_t));
    *digit_MemoryImages[n] = (uint16_t *)ps_malloc(Image_Size * sizeof(uint16_t));
    if (*digit_MemoryImages[n] == NULL) Serial.println("Why pointer after malloc is NULL ????");
#ifdef DEBUG_PSRAM
    Serial.printf("Memory addresses, n = %i, **digit_MemoryImages[] = 0x%x, digit_MemoryImages[n] = 0x%x, data = 0x%x\n", n, &digit_MemoryImages[n], *digit_MemoryImages[n],**digit_MemoryImages[n]);
    Serial.printf("Image addresses, n = %i, *Image_Names[] = 0x%x, Image_value = 0x%x\n", n, Image_Names[n], *Image_Names[n]);
    Serial.printf("Loop Iteration n = %d\n", n);
    printMem();
#endif

    for (uint16_t i = 0; i < Image_Size; i++)
    {
// Swap octets because ST7789 SPI is little endian
      *(*digit_MemoryImages[n]+i) = ((*(Image_Names[n]+i) << 8) & 0xff00) | (*(Image_Names[n]+i) >> 8);
    }


//      **(digit_MemoryImages[n]) = ((*(Image_Names[n]) << 8) & 0xff00) | (*(Image_Names[n]) >> 8);
#ifdef DEBUG_PSRAM
    Serial.printf("Image addresses, n = %i, Converted_Value[n] = 0x%x, Image_value = 0x%x\n", n, **digit_MemoryImages[n], *Image_Names[n]);
#endif

  }

// Use PSRAM
//  Serial.println("Using PSRAM malloc");
//  p_psram = (uint16_t *)ps_malloc((Image_Size * sizeof(uint16_t))*10);

#ifdef DEBUG_PSRAM
//	Serial.println();
//  printMem();
//  Serial.printf("Used PSRAM: %d\n", ESP.getPsramSize() - ESP.getFreePsram());
#endif
  delay(500);
  
// Free allocated PSRAM. (library initialization)
//  Serial.println("Free PSRAM malloc");
//  free(p_psram);
//  printMem();
  return false;
}

/*
//---------------------------------------------------------------------------------
// Allocate image display memory
//---------------------------------------------------------------------------------
bool setup_PSRAM_Images(void)
{
  uint16_t *ptr = digit_MemoryImages[0];
  uint16_t pixel = 0x0000;
#ifdef DEBUG_LCD
      Serial.println("Entered setup_PSRAM_Images");
#endif

  for (int n = 0; n < 10; n++)
  {
    ptr = (uint16_t *)malloc(Image_Size * sizeof(uint16_t)); // Size is a 16 bit space

    if (ptr == NULL)
    {
#ifdef DEBUG_LCD
      Serial.printf("Failed to allocate memory, n = %i, ptr = 0x%x, digit_MemoryImages[n] = 0x%x\n", n, ptr, &digit_MemoryImages[n]);
      while(1);
#endif
      return true;
    }

    digit_MemoryImages[n] = ptr;

#ifdef DEBUG_LCD
      Serial.printf("Allocated memory, n = %i, ptr = 0x%x, digit_MemoryImages[n] = 0x%x\n", n, ptr, digit_MemoryImages[n]);
      printMem();
      Serial.println();
#endif

// Good memory allocation for digit n, now read flash image and transpose octets into PSRAM    
    {
      for (int i = 0; i < Image_Size; i++)
      {
        pixel = *(nixie_names[n]+i);
        pixel = ((pixel << 8) & 0xff00) | (pixel >> 8);
        *(digit_MemoryImages[n]+i) = pixel;
      }
    }
    watchDogRefresh();
  }
  return false; // Success
}
*/
