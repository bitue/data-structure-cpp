import string
a = ['Oh', 'Emelia', 'to']

s = "Oh, I got two tickets for Dhaka. I and Emelia love  visiting different places very much. This time we are going to Bangladesh."


def create_new_string (arr, text):
    res =""
    text =  "Oh, I got two tickets for Dhaka. I and Emelia love  visiting different places very much. This time we are going to Bangladesh."
    text_arr = s.translate(str.maketrans('', '', string.punctuation)).split(" ")

    #text_arr = text.split(" ")
    # print(text_arr)
    for i in arr :

        if i in text_arr :
            idx_text = text_arr.index(i)
            # print(idx_text)
            res+=text_arr[idx_text + 1] + " "
    print(res)
    with open('out.txt', 'w', encoding='utf-8') as f:
        f.write(res)


dd = create_new_string(a, s)
print(dd)