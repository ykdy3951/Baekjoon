d={
    'CU':'see you',
    ':-)':'I’m happy',
    ':-(':'I’m unhappy',
    ';-)':'wink',
    ':-P':'stick out my tongue',
    '(~.~)':'sleepy',
    'TA':'totally awesome',
    'CCC':'Canadian Computing Competition',
    'CUZ':'because',
    'TY':'thank-you',
    'YW':'you’re welcome',
    'TTYL':'talk to you later'
}

for i in open(0):
    i=i.rstrip()
    print(d[i] if i in d else i)