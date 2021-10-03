#ifndef MENU_TRANSITIONS_H
#define MENU_TRANSITIONS_H

#define TRANSITION_GRAPHICS_FROM_TITLE_SCREEN()                                                              \
    /* Animate Logo and Text */                                                                              \
    logo.rect.y = logo.endPos_y + MOVE_FAST_THEN_DECELERATE(logo.startPos_y - logo.endPos_y, 1, time_anim1); \
    MENU_MOVE_TEXT_RIGHT(text_PressStart, time_anim1);                                                       \
    /* Check For Finished Animation */                                                                       \
    if (time_anim1 >= 1) {                                                                                   \
        logo.rect.y = logo.endPos_y;                                                                         \
        UPDATE_MAIN_MENU_CURSOR_POSITION_X();                                                                \
        UPDATE_MENU_CURSOR_POSITION_Y(menuCursorIndex_main);                                                 \
    }                                                                                                        \
    /* Draw Logo and Text */                                                                                 \
    SDL_RenderCopy(renderer, logo.texture, NULL, &logo.rect);                                                \
    RENDER_TEXT(text_PressStart);

#define TRANSITION_GRAPHICS_TO_TITLE_SCREEN()                                                                  \
    /* Animate Logo and Text */                                                                                \
    logo.rect.y = logo.startPos_y - MOVE_FAST_THEN_DECELERATE(logo.startPos_y - logo.endPos_y, 1, time_anim1); \
    MENU_MOVE_TEXT_LEFT(text_PressStart, time_anim1);                                                          \
    /* Check For Finished Animation */                                                                         \
    if (time_anim1 >= 1) {                                                                                     \
        logo.rect.y = logo.startPos_y;                                                                         \
        text_PressStart.rect.y = text_PressStart.startPos_y;                                                   \
    }                                                                                                          \
    /* Draw Logo and Text */                                                                                   \
    SDL_RenderCopy(renderer, logo.texture, NULL, &logo.rect);                                                  \
    RENDER_TEXT(text_PressStart);

#define TRANSITION_GRAPHICS_FROM_MAIN_MENU()        \
    /* Animate and Draw Text */                     \
    MENU_MOVE_TEXT_DOWN(text_Play, time_anim1);     \
    MENU_MOVE_TEXT_DOWN(text_Controls, time_anim1); \
    MENU_MOVE_TEXT_DOWN(text_Options, time_anim1);  \
    MENU_MOVE_TEXT_DOWN(text_Credits, time_anim1);  \
    MENU_MOVE_TEXT_DOWN(text_Quit, time_anim1);     \
    RENDER_TEXT(text_Play);                         \
    RENDER_TEXT(text_Controls);                     \
    RENDER_TEXT(text_Options);                      \
    RENDER_TEXT(text_Credits);                      \
    RENDER_TEXT(text_Quit);

#define TRANSITION_GRAPHICS_TO_MAIN_MENU(choice)             \
    /* Animate Text */                                       \
    switch (choice) {                                        \
        case 0:                                              \
            MENU_MOVE_TEXT_LEFT(text_Play, time_anim1);      \
            break;                                           \
        case 1:                                              \
            MENU_MOVE_TEXT_LEFT(text_Controls, time_anim1);  \
            break;                                           \
        case 2:                                              \
            MENU_MOVE_TEXT_LEFT(text_Options, time_anim1);   \
            break;                                           \
        case 3:                                              \
            MENU_MOVE_TEXT_LEFT(text_Credits, time_anim1);   \
            break;                                           \
        case 4:                                              \
            MENU_MOVE_TEXT_LEFT(text_Quit, time_anim1);      \
            break;                                           \
        default:                                             \
            MENU_MOVE_TEXT_UP(text_Play, time_anim1);        \
            MENU_MOVE_TEXT_UP(text_Controls, time_anim1);    \
            MENU_MOVE_TEXT_UP(text_Options, time_anim1);     \
            MENU_MOVE_TEXT_UP(text_Credits, time_anim1);     \
            MENU_MOVE_TEXT_UP(text_Quit, time_anim1);        \
            break;                                           \
    }                                                        \
    /* Check For Finished Animation */                       \
    if (time_anim1 >= 1) {                                   \
        text_Play.rect.y = text_Play.endPos_y;               \
        text_Controls.rect.y = text_Controls.endPos_y;       \
        text_Options.rect.y = text_Options.endPos_y;         \
        text_Credits.rect.y = text_Credits.endPos_y;         \
        text_Quit.rect.y = text_Quit.endPos_y;               \
        UPDATE_MAIN_MENU_CURSOR_POSITION_X();                \
        UPDATE_MENU_CURSOR_POSITION_Y(menuCursorIndex_main); \
    }                                                        \
    /* Draw Text */                                          \
    RENDER_TEXT(text_Play);                                  \
    RENDER_TEXT(text_Controls);                              \
    RENDER_TEXT(text_Options);                               \
    RENDER_TEXT(text_Credits);                               \
    RENDER_TEXT(text_Quit);

#define TRANSITION_GRAPHICS_TO_OPTIONS_MENU()                   \
    /* Animate Text */                                          \
    MENU_MOVE_TEXT_UP(text_Video, time_anim1);                  \
    MENU_MOVE_TEXT_UP(text_Sound, time_anim1);                  \
    MENU_MOVE_TEXT_UP(text_Background, time_anim1);             \
    MENU_MOVE_TEXT_UP(text_Scores, time_anim1);                 \
    /* Check For Finished Animation */                          \
    if (time_anim1 >= 1) {                                      \
        text_Video.rect.y = text_Video.endPos_y;                \
        text_Sound.rect.y = text_Sound.endPos_y;                \
        text_Background.rect.y = text_Background.endPos_y;      \
        text_Scores.rect.y = text_Scores.endPos_y;              \
        UPDATE_OPTIONS_MENU_CURSOR_POSITION_X();                \
        UPDATE_MENU_CURSOR_POSITION_Y(menuCursorIndex_options); \
    }                                                           \
    /* Draw Text */                                             \
    RENDER_TEXT(text_Video);                                    \
    RENDER_TEXT(text_Sound);                                    \
    RENDER_TEXT(text_Background);
    //RENDER_TEXT(text_Scores);

#define TRANSITION_TO_STATE_WITH_TIMER(timer, time, state) \
    if (timer >= time) { \
        timer = 0; \
        programState = state; \
    }

#endif