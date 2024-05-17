import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import classification_report, accuracy_score
from sklearn.model_selection import GridSearchCV
# 数据输入
data = {
    "氯": [0.0560, 0.0400, 0.0500, 0.0450, 0.0380, 0.0300, 0.0340, 0.0300, 0.0840, 0.0850, 0.0640, 0.0540, 0.0480, 0.0450, 0.0690],
    "硫化氯": [0.084, 0.055, 0.074, 0.050, 0.130, 0.110, 0.095, 0.090, 0.066, 0.076, 0.072, 0.065, 0.089, 0.092, 0.087],
    "二氧化硫": [0.031, 0.100, 0.041, 0.110, 0.079, 0.070, 0.058, 0.068, 0.029, 0.019, 0.020, 0.022, 0.062, 0.072, 0.027],
    "碳四": [0.038, 0.110, 0.048, 0.100, 0.170, 0.160, 0.160, 0.180, 0.320, 0.300, 0.250, 0.280, 0.260, 0.200, 0.050],
    "环氧氯丙烷": [0.0081, 0.022, 0.0071, 0.025, 0.058, 0.050, 0.200, 0.220, 0.012, 0.010, 0.028, 0.021, 0.038, 0.035, 0.089],
    "环己烷": [0.0220, 0.0073, 0.0200, 0.0063, 0.0430, 0.0460, 0.0290, 0.0390, 0.0410, 0.0400, 0.0380, 0.0400, 0.0360, 0.0320, 0.0210],
    "污染类别": [1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1]
}
df = pd.DataFrame(data)
# 数据分割
X = df.drop("污染类别", axis=1)
y = df["污染类别"]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)
# 标准化
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)
# SVM模型的网格搜索来优化参数
param_grid_svm = {'C': [0.1, 1, 10, 100], 'gamma': [0.1, 1, 10, 100], 'kernel': ['rbf', 'linear']}
svm = SVC()
grid_svm = GridSearchCV(svm, param_grid_svm, cv=5, scoring='accuracy')
grid_svm.fit(X_train_scaled, y_train)
best_params_svm = grid_svm.best_params_
svm_best = SVC(**best_params_svm)
svm_best.fit(X_train_scaled, y_train)
# 在测试集上评估SVM模型
y_pred_svm = svm_best.predict(X_test_scaled)
svm_accuracy = accuracy_score(y_test, y_pred_svm)
svm_classification_report = classification_report(y_test, y_pred_svm)
print(f"Best parameters for SVM: {best_params_svm}")
print("SVM Test Accuracy:", svm_accuracy)
print("SVM Classification Report:")
print(svm_classification_report)
test = pd.DataFrame({
    "氯": [0.052,0.042,0.30,0.074],
    "硫化氯": [0.084,0.055,0.112,0.083],
    "二氧化硫": [0.021,0.110,0.072,0.105],
    "碳四": [0.037,0.110,0.160,0.190],
    "环氧氯丙烷": [0.0071,0.021,0.056,0.02],
    "环己烷": [0.022,0.0073,0.021,1.0],
})
test = scaler.transform(test)
# 在验证集上评估SVM模型
y_test_svm = svm_best.predict(test)
print(y_test_svm)
