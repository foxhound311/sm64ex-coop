#ifndef GFX_WINDOW_MANAGER_API_H
#define GFX_WINDOW_MANAGER_API_H

#include <stdint.h>
#include <stdbool.h>

// special value for window position that signifies centered position
#define WAPI_WIN_CENTERPOS 0xFFFFFFFF

typedef bool (*kb_callback_t)(int code);

struct GfxWindowManagerAPI {
    void (*init)(const char *window_title);
    void (*set_keyboard_callbacks)(kb_callback_t on_key_down, kb_callback_t on_key_up, void (*on_all_keys_up)(void), void (*on_text_input)(char*));
#ifdef TOUCH_CONTROLS
    void (*set_touchscreen_callbacks)(void (*down)(void* event), void (*motion)(void* event), void (*up)(void* event));
#endif
    void (*main_loop)(void (*run_one_game_iter)(void));
    void (*get_dimensions)(uint32_t *width, uint32_t *height);
    void (*handle_events)(void);
    bool (*start_frame)(void);
    void (*swap_buffers_begin)(void);
    void (*swap_buffers_end)(void);
    double (*get_time)(void); // For debug
    void (*shutdown)(void);
    void (*start_text_input)(void);
    void (*stop_text_input)(void);
    char* (*get_clipboard_text)(void);
    void (*set_clipboard_text)(char*);
    void (*set_cursor_visible)(bool);
    void (*delay)(unsigned int ms);
};

#endif
