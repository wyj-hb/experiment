import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import  association_rules
from apyori import apriori
# 加载数据
data_path = '../data/adult.csv'  # 确保路径正确
df = pd.read_csv(data_path, delimiter=',', header=0)

# 筛选收入大于 50k 的数据
df_filtered = df[df['income'] == ' >50K']

# 检查筛选后数据的大小
print("筛选后的数据大小:", df_filtered.shape)
# 选择相关的类别变量
categories = df_filtered[['workclass', 'education', 'marital-status', 'occupation', 'relationship', 'race', 'sex']]
# 将数据转换为列表格式
dataset = categories.values.tolist()
# Apriori
ass_rules = apriori(dataset, min_support=0.2, min_confidence=0.6)
all_strong_relation = []
# 提取相应的数据
for rule in ass_rules:
    support = round(rule.support, 3)  # 获取一个项集的支持度,小数部分保留三位
    # 由这个项集产生的所有强关联.
    for i in rule.ordered_statistics:
        head_set = list(i.items_base)
        # 前件为空的时候关联规则没有啥意义，因此删去
        if head_set == []:
            continue
        tail_set = list(i.items_add)
        confidence = round(i.confidence, 3)  # 小数部分保留三位
        lift = round(i.lift, 3)  # 小数部分保留三位
        # 把这些数据转换为dataframe的格式
        relation = str(head_set) + "→" + str(tail_set)
        all_strong_relation.append([relation, support, confidence, lift])
strong_Relation = pd.DataFrame(all_strong_relation, columns=["关联规则", "支持度", "置信度", "提升度"])
strong_Relation_sorted = strong_Relation.sort_values(by=['提升度'], ascending=[False])
# 选择置信度前10的关联规则
top10_confidence_rules = strong_Relation_sorted.head(10)
# 打印置信度前10的关联规则
print("--------------置信度前10的关联规则------------")
print(top10_confidence_rules)