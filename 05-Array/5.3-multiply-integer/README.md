# multiply two arbitrary-precision integer

when doing multiplication, don't use carry instaad, use 
result[i+j+1] += num1[i] * num2[j];
result[i+j] += result[i+j+1] / 10;
result[i+j+1] %= 10;