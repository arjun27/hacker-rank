# triplets
# 6 on 15 correct

def create_dict(dict_ans, ar):
    for a in ar:
        keys = dict_ans.keys()
        for key in keys:
            if key < a:
                sub_keys = dict_ans[key].keys()
                for sub_key in sub_keys:
                    if sub_key < a:
                        if not a in dict_ans[key][sub_key]:
                            dict_ans[key][sub_key].append(a)
                if not a in sub_keys:
                    dict_ans[key][a] = []
        if not a in keys:
            dict_ans[a] = {}
    return dict_ans

def count_triplets(dict_ans):
    count = 0
    for key in dict_ans:
        for sub_key in dict_ans[key]:
            count += len(dict_ans[key][sub_key])
    return count

dict_ans = {}
n = int(raw_input())
ar = [int(i) for i in raw_input().strip().split()]
dict_ans = create_dict(dict_ans, ar)
print count_triplets(dict_ans)