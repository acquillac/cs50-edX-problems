#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Setting original values
            double originalRed = image[i][j].rgbtRed;
            double originalGreen = image[i][j].rgbtGreen;
            double originalBlue = image[i][j].rgbtBlue;

            // calulate the average rgb value
            float rgb = originalRed + originalGreen + originalBlue;

            // round rgb to the nearest whole number
            float average = round(rgb / 3);

            // setting new rgb values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Setting original values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Setting sepia values
            // If sepaia is greater than 255 reset the value to 255
            float sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            float sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            float sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // setting new rgb values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int j = 0; j < width / 2; j++)
    {
        for (int i = 0; i < height; i++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // creating copy
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    // blur original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rSum = 0;
            int gSum = 0;
            int bSum = 0;

            float counter = 0;

            //original pixel
            if (i >= 0 && j >= 0)
            {
                rSum += copy[i][j].rgbtRed;
                gSum += copy[i][j].rgbtGreen;
                bSum += copy[i][j].rgbtBlue;
                counter++;
            }
            // left
            if (i >= 0 && j - 1 >= 0)
            {
                rSum += copy[i][j - 1].rgbtRed;
                gSum += copy[i][j - 1].rgbtGreen;
                bSum += copy[i][j - 1].rgbtBlue;
                counter++;
            }

            // right
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                rSum += copy[i][j + 1].rgbtRed;
                gSum += copy[i][j + 1].rgbtGreen;
                bSum += copy[i][j + 1].rgbtBlue;
                counter++;
            }

            // top
            if (i - 1 >= 0 && j >= 0)
            {
                rSum += copy[i - 1][j].rgbtRed;
                gSum += copy[i - 1][j].rgbtGreen;
                bSum += copy[i - 1][j].rgbtBlue;
                counter++;
            }

            // bottom
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                rSum += copy[i + 1][j].rgbtRed;
                gSum += copy[i + 1][j].rgbtGreen;
                bSum += copy[i + 1][j].rgbtBlue;
                counter++;
            }

            // top left
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                rSum += copy[i - 1][j - 1].rgbtRed;
                gSum += copy[i - 1][j - 1].rgbtGreen;
                bSum += copy[i - 1][j - 1].rgbtBlue;
                counter++;
            }

            // top right
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                rSum += copy[i - 1][j + 1].rgbtRed;
                gSum += copy[i - 1][j + 1].rgbtGreen;
                bSum += copy[i - 1][j + 1].rgbtBlue;
                counter++;
            }

            // bottom left
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                rSum += copy[i + 1][j - 1].rgbtRed;
                gSum += copy[i + 1][j - 1].rgbtGreen;
                bSum += copy[i + 1][j - 1].rgbtBlue;
                counter++;
            }

            // bottom right
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                rSum += copy[i + 1][j + 1].rgbtRed;
                gSum += copy[i + 1][j + 1].rgbtGreen;
                bSum += copy[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            // setting blur to image
            image[i][j].rgbtRed = round(rSum / counter);
            image[i][j].rgbtGreen = round(gSum / counter);
            image[i][j].rgbtBlue = round(bSum / counter);
        }
    }

    return;
}

