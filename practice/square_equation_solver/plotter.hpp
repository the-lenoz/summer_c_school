#ifndef PLOTTER_DECLARED
#define PLOTTER_DECLARED


struct Vector2DDouble
{
    double x;
    double y;
};

struct Vector2DInt
{
    int x;
    int y;
};

struct Vector2DUInt
{
    unsigned int x;
    unsigned int y;
};

char* plot_function(double (f)(double), Vector2DInt plot_window_size, Vector2DDouble plot_real_size);


Vector2DInt map_var_values_to_plotter_window(Vector2DDouble values, Vector2DDouble plot_center,
                                             Vector2DInt plot_window_size, Vector2DDouble plot_real_size);


Vector2DDouble map_plotter_window_coords_to_var_values(Vector2DInt coords, Vector2DDouble plot_center,
                                             Vector2DInt plot_window_size, Vector2DDouble plot_real_size);




#endif // PLOTTER_DECLARED