import cv2
import numpy as np
def calculate_vegetation_coverage(image_path):
    # 读取图片
    img = cv2.imread(image_path)
    # img = img[:,:,:3]
    # img = cv2.imread(image_path)
    # 将图片从BGR色彩空间转换到HSV色彩空间，便于颜色过滤
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    # 定义绿色的HSV范围，这可能需要根据实际情况调整
    lower_green = np.array([40, 43, 46])  # HSV中绿色的较低阈值
    upper_green = np.array([70, 255, 255])  # HSV中绿色的较高阈值

    # 根据绿色的HSV范围创建掩模
    mask = cv2.inRange(hsv, lower_green, upper_green)
    # 应用开运算和闭运算去除噪声和小物体
    kernel = np.ones((5, 5), np.uint8)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
    mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
    # 使用掩模找到绿色区域
    green_areas = cv2.bitwise_and(img, img, mask=mask)
    # 计算绿色像素的数量
    total_pixels = img.shape[0] * img.shape[1]
    green_pixels = np.count_nonzero(mask)
    # 计算植被覆盖率
    vegetation_coverage = (green_pixels / total_pixels) * 100
    # 显示原图和绿色区域识别结果
    cv2.imshow('Original Image', img)
    cv2.imshow('Green Areas Detected', green_areas)
    print(f'Vegetation Coverage: {vegetation_coverage:.2f}%')
    cv2.waitKey(0)
    cv2.destroyAllWindows()
# 调用函数，传入航拍图片路径
calculate_vegetation_coverage('../img/fujianer.tif')