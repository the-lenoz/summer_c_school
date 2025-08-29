#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "plotter.hpp"
#include "mathematics.hpp"




char* plot_function(double (f)(double),  Vector2DInt plot_window_size, Vector2DDouble plot_real_size)
{
    Vector2DDouble plot_center = {};
    plot_center.x = get_func_extremum(f);
    plot_center.y = f(plot_center.x);

    Vector2DInt plot_window_center = {};
    plot_window_center.x = plot_window_size.x & 1 ? ((plot_window_size.x - 2) >> 1) - 1 : (plot_window_size.x - 2) >> 1;
    plot_window_center.y = plot_window_size.y & 1 ? (plot_window_size.y >> 1) - 1 : plot_window_size.y >> 1;

    Vector2DInt current_window_point = {};
    Vector2DDouble current_plot_point = {};


    int plot_array_size = plot_window_size.x * plot_window_size.y;
    char* plot_array = (char*) calloc((size_t) plot_array_size + 1, sizeof(char));
    char** plot_array_2D = (char**) calloc((size_t) plot_window_size.y, sizeof(char*));

    for (int y = 0; y < plot_window_size.y; ++y)
    {
        plot_array_2D[y] = &plot_array[y * plot_window_size.x];
    }


    Vector2DInt zero_coords = map_var_values_to_plotter_window({0, 0}, plot_center, plot_window_size, plot_real_size);

    for ( int y = 0; y < plot_window_size.y; ++y)
    {
        if (y > 0 && y < plot_window_size.y - 1)
        {
            current_window_point = {.x = 0, .y=(int)y - plot_window_center.y};
            current_plot_point = map_plotter_window_coords_to_var_values(current_window_point, plot_center, plot_window_size, plot_real_size);
            
            snprintf(&(plot_array_2D[plot_window_size.y - 1 - y][plot_window_size.x - 11]), 10, " %8f", current_plot_point.y);
            for (int i = 2; i < 12; ++i) 
                if (plot_array_2D[plot_window_size.y - 1 - y][plot_window_size.x - i] == '\0') 
                    plot_array_2D[plot_window_size.y - 1 - y][plot_window_size.x - i] = ' ';
        }
        plot_array_2D[plot_window_size.y - 1 - y][plot_window_size.x - 1] = '\n';


        for ( int x = 0; x < plot_window_size.x - 1; ++x)
        {
            if (x == 0 || x == (plot_window_size.x - 12) || y == 0 || y == (plot_window_size.y - 1)) // border
            {
                plot_array_2D[plot_window_size.y - 1 - y][x] = '%';
            }
            else if ((int)x - plot_window_center.x== zero_coords.x)
            {  
                plot_array_2D[plot_window_size.y - 1 - y][x] = '|';
            }
            else if (((int)y - plot_window_center.y == zero_coords.y) && plot_array_2D[plot_window_size.y - 1 - y][x] == '\0')
            {  
                plot_array_2D[plot_window_size.y - 1 - y][x] = '-';
            }
            else if (plot_array_2D[plot_window_size.y - 1 - y][x] == '\0')
            {
                plot_array_2D[plot_window_size.y - 1 - y][x] = ' ';
            }
        }
        
    }
    int prev_y = 0;
    int prev_exists = 0;
    for ( int x = 0; x < plot_window_size.x - 12; ++x)
    {
        current_window_point = {.x = (int)x - plot_window_center.x, .y=0};
        current_plot_point = map_plotter_window_coords_to_var_values(current_window_point, plot_center, plot_window_size, plot_real_size);

        current_plot_point.y = f(current_plot_point.x);
        current_window_point = map_var_values_to_plotter_window(current_plot_point, plot_center, plot_window_size, plot_real_size);

        if (prev_exists)
        {
            if (current_window_point.y < prev_y)
                for (int y = current_window_point.y; y < prev_y; ++y)
                {
                    if ((y + plot_window_center.y) < plot_window_size.y &&
                        (y + plot_window_center.y) > 0 &&
                        plot_array_2D[plot_window_size.y - 1 - y - plot_window_center.y][x] != '%')
                        plot_array_2D[plot_window_size.y - 1 - y - plot_window_center.y][x] = '$';
                }
            else 
            {
                for (int y = current_window_point.y; y > prev_y; --y)
                {
                    if ((y + plot_window_center.y) < plot_window_size.y &&
                        (y + plot_window_center.y) > 0 &&
                        plot_array_2D[plot_window_size.y - 1 - y - plot_window_center.y][x] != '%')
                        plot_array_2D[plot_window_size.y - 1 - y - plot_window_center.y][x] = '$';
                };
                if (current_window_point.y == prev_y)
                {
                    if ((prev_y + plot_window_center.y) < plot_window_size.y &&
                        (prev_y + plot_window_center.y) > 0 &&
                        plot_array_2D[plot_window_size.y - 1 - prev_y - plot_window_center.y][x] != '%')
                        plot_array_2D[plot_window_size.y - 1 - prev_y - plot_window_center.y][x] = '$';
                }
            }
                
        }
        prev_y = current_window_point.y;
        prev_exists = 1;
    }
    free(plot_array_2D);

    return plot_array;
}


Vector2DInt map_var_values_to_plotter_window(Vector2DDouble values, Vector2DDouble plot_center,
                                              Vector2DInt plot_window_size, Vector2DDouble plot_real_size)
{
    Vector2DInt window_point_coords = {};
    window_point_coords.x = (int)( round((values.x - plot_center.x) / plot_real_size.x * plot_window_size.x));
    window_point_coords.y = (int)( round((values.y - plot_center.y) / plot_real_size.y * plot_window_size.y));

    return window_point_coords;
}


Vector2DDouble map_plotter_window_coords_to_var_values(Vector2DInt coords, Vector2DDouble plot_center,
                                              Vector2DInt plot_window_size, Vector2DDouble plot_real_size)
{
    Vector2DDouble var_values = {};
    var_values.x = (((double) coords.x) / plot_window_size.x * plot_real_size.x + plot_center.x);
    var_values.y = (((double) coords.y) / plot_window_size.y * plot_real_size.y + plot_center.y);

    return var_values;
}