import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import matplotlib
matplotlib.use('TkAgg')

# 数据输入
countries_data = {
    "国别": ["中国", "美国", "日本", "德国", "英国", "法国", "意大利", "加拿大", "澳大利亚", "俄罗斯",
             "捷克", "波兰", "匈牙利", "南斯拉夫*", "罗马尼亚", "保加利亚", "印度", "印度尼西亚", "尼日利亚", "墨西哥", "巴西"],
    "森林面积": [11978, 28446, 2501, 1028, 210, 1458, 635, 32613, 10700, 92000,
                  458, 868, 161, 929, 634, 385, 6748, 2180, 1490, 4850, 57500],
    "森林覆盖率": [12.5, 30.4, 67.2, 28.4, 8.6, 26.7, 21.1, 32.7, 13.9, 41.1,
                    35.8, 27.8, 17.4, 36.3, 26.7, 34.7, 20.5, 84.0, 16.1, 24.6, 67.6],
    "林木蓄积量": [93.5, 202, 24.8, 14, 1.5, 16, 3.6, 192.8, 10.5, 841.5,
                    8.9, 11.4, 2.5, 11.4, 11.3, 2.5, 29, 33.7, 0.8, 32.6, 238],
    "草原面积": [31908, 23754, 58, 599, 1147, 1288, 514, 2385, 45190, 37370,
                 168, 405, 129, 640, 447, 200, 1200, 1200, 2090, 7450, 15900]
}
df_countries = pd.DataFrame(countries_data)
# 数据预处理，去除“国别”列，因为它是非数值数据
X = df_countries.drop("国别", axis=1)
# 使用Elbow方法确定最佳聚类数K
wcss = []
for i in range(1, 11):
    kmeans = KMeans(n_clusters=i, init='k-means++', max_iter=300, n_init=10, random_state=42)
    kmeans.fit(X)
    wcss.append(kmeans.inertia_)
plt.figure(figsize=(10, 6))
plt.plot(range(1, 11), wcss)
plt.title('Elbow Method')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')
plt.savefig('elbow.png')
# 根据Elbow图选择最佳K值并执行K-means聚类
best_k = 3
kmeans = KMeans(n_clusters=best_k, init='k-means++', max_iter=300, n_init=10, random_state=42)
y_kmeans = kmeans.fit_predict(X)
# 将聚类结果添加到原始数据框中
df_countries['Cluster'] = y_kmeans
clusters = df_countries.groupby('Cluster').apply(lambda x: x['国别'].tolist())

# 输出每个簇中的国家名称
for cluster, countries in clusters.items():
    print(f"Cluster {cluster}:")
    print(countries)
    print()  # 打印一个空行以便区分不同的簇
# 输出聚类结果
df_countries.to_excel('out.xlsx',index=False)
