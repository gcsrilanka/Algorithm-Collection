const isPalindrome = (string) => {

  const newString = string.split('').reverse().join('');

  if (string !== newString) {
    console.log("not a palindrome");
  }
  
  console.log("palindrome");

};

isPalindrome("NITIN");