import os

CHAR=256

def badCharacterTable(pattern):
    length=len(pattern)
    badchar=[length]*CHAR
    
    for i in range(length-1):
        badchar[ord(pattern[i])]=length-i
    
    return badchar

def stringSearch(text,pattern):
    textlen=len(text)
    patternlen=len(pattern)
    badchar=badCharacterTable(pattern)    
    occurance=[]
    position=0
    if(text=="" or pattern==""):
        print("Text:"+text+"\nPattern:"+pattern+"\nTotal Number matched:"+str(len(occurance))+"\nPositions matched:"+', '.join(occurance))
        return
    
    while(position<=(textlen-patternlen)):
        j=patternlen-1
        while(j>=0 and (text[position+j]==pattern[j] or pattern[j]=='_')):
            j=j-1
            
        if(j==-1):
            occurance.append(str(position+1))
            position=position+1
        else:
            position=position+ max(1,j-badchar[ord(text[position+j])])
    print("Text:"+text+"\nPattern:"+pattern+"\nTotal Number matched:"+str(len(occurance))+"\nPositions matched:"+', '.join(occurance))
        
def main():
    while (1):
        text=input("Enter a sample text:")
        pattern=input("Enter a pattern:")
        stringSearch(text,pattern)
        print("\nEnter 1 to test Continue\nEnter 0 to EXIT")
        n=input("Enter your choise: ")
        if(n=='0'):
            return


if __name__=="__main__":
    main()
