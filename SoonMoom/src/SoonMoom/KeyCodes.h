#pragma once
#include "SoonMoom/Core.h"



#ifdef SM_WINDOWS_GLFW_INPUT_CODE
//From glfw3.h
/* Printable keys */
#define SM_KEY_SPACE              32
#define SM_KEY_APOSTROPHE         39  /* ' */
#define SM_KEY_COMMA              44  /* , */
#define SM_KEY_MINUS              45  /* - */
#define SM_KEY_PERIOD             46  /* . */
#define SM_KEY_SLASH              47  /* / */
#define SM_KEY_0                  48
#define SM_KEY_1                  49
#define SM_KEY_2                  50
#define SM_KEY_3                  51
#define SM_KEY_4                  52
#define SM_KEY_5                  53
#define SM_KEY_6                  54
#define SM_KEY_7                  55
#define SM_KEY_8                  56
#define SM_KEY_9                  57
#define SM_KEY_SEMICOLON          59  /* ; */
#define SM_KEY_EQUAL              61  /* = */
#define SM_KEY_A                  65
#define SM_KEY_B                  66
#define SM_KEY_C                  67
#define SM_KEY_D                  68
#define SM_KEY_E                  69
#define SM_KEY_F                  70
#define SM_KEY_G                  71
#define SM_KEY_H                  72
#define SM_KEY_I                  73
#define SM_KEY_J                  74
#define SM_KEY_K                  75
#define SM_KEY_L                  76
#define SM_KEY_M                  77
#define SM_KEY_N                  78
#define SM_KEY_O                  79
#define SM_KEY_P                  80
#define SM_KEY_Q                  81
#define SM_KEY_R                  82
#define SM_KEY_S                  83
#define SM_KEY_T                  84
#define SM_KEY_U                  85
#define SM_KEY_V                  86
#define SM_KEY_W                  87
#define SM_KEY_X                  88
#define SM_KEY_Y                  89
#define SM_KEY_Z                  90
#define SM_KEY_LEFT_BRACKET       91  /* [ */
#define SM_KEY_BACKSLASH          92  /* \ */
#define SM_KEY_RIGHT_BRACKET      93  /* ] */
#define SM_KEY_GRAVE_ACCENT       96  /* ` */
#define SM_KEY_WORLD_1            161 /* non-US #1 */
#define SM_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define SM_KEY_ESCAPE             256
#define SM_KEY_ENTER              257
#define SM_KEY_TAB                258
#define SM_KEY_BACKSPACE          259
#define SM_KEY_INSERT             260
#define SM_KEY_DELETE             261
#define SM_KEY_RIGHT              262
#define SM_KEY_LEFT               263
#define SM_KEY_DOWN               264
#define SM_KEY_UP                 265
#define SM_KEY_PAGE_UP            266
#define SM_KEY_PAGE_DOWN          267
#define SM_KEY_HOME               268
#define SM_KEY_END                269
#define SM_KEY_CAPS_LOCK          280
#define SM_KEY_SCROLL_LOCK        281
#define SM_KEY_NUM_LOCK           282
#define SM_KEY_PRINT_SCREEN       283
#define SM_KEY_PAUSE              284
#define SM_KEY_F1                 290
#define SM_KEY_F2                 291
#define SM_KEY_F3                 292
#define SM_KEY_F4                 293
#define SM_KEY_F5                 294
#define SM_KEY_F6                 295
#define SM_KEY_F7                 296
#define SM_KEY_F8                 297
#define SM_KEY_F9                 298
#define SM_KEY_F10                299
#define SM_KEY_F11                300
#define SM_KEY_F12                301
#define SM_KEY_F13                302
#define SM_KEY_F14                303
#define SM_KEY_F15                304
#define SM_KEY_F16                305
#define SM_KEY_F17                306
#define SM_KEY_F18                307
#define SM_KEY_F19                308
#define SM_KEY_F20                309
#define SM_KEY_F21                310
#define SM_KEY_F22                311
#define SM_KEY_F23                312
#define SM_KEY_F24                313
#define SM_KEY_F25                314
#define SM_KEY_KP_0               320
#define SM_KEY_KP_1               321
#define SM_KEY_KP_2               322
#define SM_KEY_KP_3               323
#define SM_KEY_KP_4               324
#define SM_KEY_KP_5               325
#define SM_KEY_KP_6               326
#define SM_KEY_KP_7               327
#define SM_KEY_KP_8               328
#define SM_KEY_KP_9               329
#define SM_KEY_KP_DECIMAL         330
#define SM_KEY_KP_DIVIDE          331
#define SM_KEY_KP_MULTIPLY        332
#define SM_KEY_KP_SUBTRACT        333
#define SM_KEY_KP_ADD             334
#define SM_KEY_KP_ENTER           335
#define SM_KEY_KP_EQUAL           336
#define SM_KEY_LEFT_SHIFT         340
#define SM_KEY_LEFT_CONTROL       341
#define SM_KEY_LEFT_ALT           342
#define SM_KEY_LEFT_SUPER         343
#define SM_KEY_RIGHT_SHIFT        344
#define SM_KEY_RIGHT_CONTROL      345
#define SM_KEY_RIGHT_ALT          346
#define SM_KEY_RIGHT_SUPER        347
#define SM_KEY_MENU               348
#endif // SM_INPUT_CODE