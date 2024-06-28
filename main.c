#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    void *image;
    int img_width;
    int img_height;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_data;

int on_destroy(t_data *data)
{
    if (data->image)
    {
        mlx_destroy_image(data->mlx_ptr, data->image);
        data->image = NULL;
    }
    if (data->win_ptr)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    }
    if (data->mlx_ptr)
    {
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
    }
    exit(0);
    return (0);
}

int on_keypress(int keysym, t_data *data)
{
    printf("Pressed key: %d\n", keysym);
    if (keysym == 65307) // Escape key
    {
        on_destroy(data);
        return (1);
    }
    return (0);
}

void put_pixel_to_image(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < data->img_width && y >= 0 && y < data->img_height)
    {
        dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
        *(unsigned int*)dst = color;
    }
}

void verify_image_data(t_data *data)
{
    printf("First 100 bytes of image data after manipulation:\n");
    for (int i = 0; i < 100; ++i)
    {
        printf("%02x ", (unsigned char)data->addr[i]);
        if (i % 16 == 15)
            printf("\n");
    }
    printf("\n");
}

int main(void)
{
    t_data data;

    data.img_width = 600;
    data.img_height = 400;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        fprintf(stderr, "Failed to initialize MLX\n");
        return (1);
    }

    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "Direct Image Test");
    if (!data.win_ptr)
    {
        fprintf(stderr, "Failed to create window\n");
        free(data.mlx_ptr);
        return (1);
    }

    // Register key release hook
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

    // Register destroy hook
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    // Create a new image instead of loading from file
    data.image = mlx_new_image(data.mlx_ptr, data.img_width, data.img_height);
    if (!data.image)
    {
        fprintf(stderr, "Failed to create new image\n");
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }

    printf("New image created successfully\n");
    printf("Image width: %d, height: %d\n", data.img_width, data.img_height);

    data.addr = mlx_get_data_addr(data.image, &data.bpp, &data.line_length, &data.endian);
    if (!data.addr)
    {
        fprintf(stderr, "Failed to get image data address\n");
        mlx_destroy_image(data.mlx_ptr, data.image);
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }

    printf("First 100 bytes of image data:\n");
    for (int i = 0; i < 100; ++i)
    {
        printf("%02x ", (unsigned char)data.addr[i]);
        if (i % 16 == 15)
            printf("\n");
    }
    printf("\n");

    // Drawing simple pattern
    for (int y = 0; y < data.img_height; y++)
    {
        for (int x = 0; x < data.img_width; x++)
        {
            if ((x + y) % 2 == 0)
            {
                put_pixel_to_image(&data, x, y, 0xFF0000); // Red color
            }
            else
            {
                put_pixel_to_image(&data, x, y, 0x0000FF); // Blue color
            }
        }
    }

    // Verify image data after manipulation
    verify_image_data(&data);

    // Put the modified image to window
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.image, 0, 0);

    // Loop over the MLX pointer
    mlx_loop(data.mlx_ptr);

    return (0);
}