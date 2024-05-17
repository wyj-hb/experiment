import numpy as np
import tifffile as tf           #tifffile是tiff文件的读取库
from PIL import Image
import cv2 as  cv
path = r'../img/2-30m3DSM.tif'
img_tf = tf.imread(path)
img_tf = img_tf[:,:,:3]
print(img_tf.shape)
hsv = cv.cvtColor(img_tf, cv.COLOR_BGR2HSV)
#set the lower and upper bounds for the green hue
lower_green = np.array([45, 43, 46])  # HSV中绿色的较低阈值
upper_green = np.array([82, 255, 255])  # HSV中绿色的较高阈值
lower_gray = np.array([0,0,0])  # H: [0, 180], S: 0, V: 0
upper_gray = np.array([180,60,250])  # H: [0, 180], S: 很低的数值, V: 255
# 使用位运算符"or"合并掩模
# 创建绿色的掩模
mask_green = cv.inRange(hsv, lower_green, upper_green)
# 创建灰色的掩模
mask_gray = cv.inRange(hsv, lower_gray, upper_gray)
mask_combined = cv.bitwise_or(mask_green, mask_gray)
# 计算总像素数
total_pixels = mask_combined.size
# 计算非零像素数（即颜色范围内的像素）
non_zero_pixels = np.count_nonzero(mask_combined)
# 计算占比
percentage = (non_zero_pixels / total_pixels) * 100
print(f"颜色范围内的像素占比: {percentage:.2f}%")
# 使用合并后的掩模对原始图像进行位运算
res = cv.bitwise_and(img_tf, img_tf, mask=mask_combined)
# 创建可调整大小的窗口以显示图像
cv.namedWindow("res", cv.WINDOW_NORMAL)
cv.namedWindow("mask_combined", cv.WINDOW_NORMAL)
cv.namedWindow("mask_green", cv.WINDOW_NORMAL)
cv.namedWindow("mask_gray", cv.WINDOW_NORMAL)
cv.namedWindow("origin", cv.WINDOW_NORMAL)
# 显示图像
cv.imshow("mask_combined", mask_combined)
cv.imshow("mask_green", mask_green)
cv.imshow("mask_gray", mask_gray)
cv.imshow("res", res)
if cv.waitKey(0):
    cv.destroyAllWindows()