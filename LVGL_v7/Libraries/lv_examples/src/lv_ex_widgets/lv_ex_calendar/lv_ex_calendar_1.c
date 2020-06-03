#include "../../../lv_examples.h"
#include <stdio.h>

#if LV_USE_CALENDAR

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t * date = lv_calendar_get_pressed_date(obj);
        if(date) {
            printf("Clicked date: %02d.%02d.%d\n", date->day, date->month, date->year);
        }
    }
}

void lv_ex_calendar_1(void)
{
    lv_obj_t  * calendar = lv_calendar_create(lv_scr_act(), NULL);
    lv_obj_set_size(calendar, 235, 235);
    lv_obj_align(calendar, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_event_cb(calendar, event_handler);

    /*Set the today*/
    lv_calendar_date_t today;
    today.year = 2018;
    today.month = 10;
    today.day = 23;

    lv_calendar_set_today_date(calendar, &today);
    lv_calendar_set_showed_date(calendar, &today);

    /*Highlight some days*/
    static lv_calendar_date_t highlihted_days[3];       /*Only it's pointer will be saved so should be static*/
    highlihted_days[0].year = 2018;
    highlihted_days[0].month = 10;
    highlihted_days[0].day = 6;

    highlihted_days[1].year = 2018;
    highlihted_days[1].month = 10;
    highlihted_days[1].day = 11;

    highlihted_days[2].year = 2018;
    highlihted_days[2].month = 11;
    highlihted_days[2].day = 22;

    lv_calendar_set_highlighted_dates(calendar, highlihted_days, 3);
}

#endif
