s = "i am a data scientist and i teach at heycoach"

words = s.split(" ")

words.sort(key=len)

print(" ".join(words))