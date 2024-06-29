// Let's make our calculator working
document.addEventListener("keydown", textKeyboard);
document.addEventListener("keydown", pressedKey);
document.addEventListener("click", textClick);
document.addEventListener("click", pressedKey);

// Function to allow the user to write using the keyboard
function textKeyboard(e) {
    const textZone = document.getElementsByClassName("res-container")[0];
    const keyValue = e.keyCode;
    const button = document.querySelector(`.key[data-key="${keyValue}"]`);

    // Add the active class to the clicked key
    button.classList.add('key-active');

    // Then removes it after a short delay
    setTimeout(() => {
        button.classList.remove('key-active');
    }, 100);

    // Switch statement to add text to the text zone when key is pressed
    switch (keyValue) {
        case 96:
            textZone.innerHTML += `0`;
            break;
        case 97:
            textZone.innerHTML += `1`;
            break;
        case 98:
            textZone.innerHTML += `2`;
            break;
        case 99:
            textZone.innerHTML += `3`;
            break;
        case 100:
            textZone.innerHTML += `4`;
            break;
        case 101:
            textZone.innerHTML += `5`;
            break;
        case 102:
            textZone.innerHTML += `6`;
            break;
        case 103:
            textZone.innerHTML += `7`;
            break;
        case 104:
            textZone.innerHTML += `8`;
            break;
        case 105:
            textZone.innerHTML += `9`;
            break;
        case 106:
            textZone.innerHTML += `*`;
            break;
        case 107:
            textZone.innerHTML += `+`;
            break;
        case 109:
            textZone.innerHTML += `-`;
            break;
        case 111:
            textZone.innerHTML += `/`;
            break;
        case 53:
            textZone.innerHTML += `%`;
            break;
        case 13:
            calculate();
            break;
    }
}

// Function to allow the user to write using the mouse
function textClick(e) {
    const textZone = document.getElementsByClassName("res-container")[0];
    const button = e.target;
    const buttonValue = button.innerHTML;

    // Switch statement to add text to the text zone when key is clicked
    switch (buttonValue) {
        case '0':
            textZone.innerHTML += `0`;
            break;
        case '1':
            textZone.innerHTML += `1`;
            break;
        case '2':
            textZone.innerHTML += `2`;
            break;
        case '3':
            textZone.innerHTML += `3`;
            break;
        case '4':
            textZone.innerHTML += `4`;
            break;
        case '5':
            textZone.innerHTML += `5`;
            break;
        case '6':
            textZone.innerHTML += `6`;
            break;
        case '7':
            textZone.innerHTML += `7`;
            break;
        case '8':
            textZone.innerHTML += `8`;
            break;
        case '9':
            textZone.innerHTML += `9`;
            break;
        case '*':
            textZone.innerHTML += `*`;
            break;
        case '+':
            textZone.innerHTML += `+`;
            break;
        case '-':
            textZone.innerHTML += `-`;
            break;
        case '/':
            textZone.innerHTML += `/`;
            break;
        case '%':
            textZone.innerHTML += `%`;
            break;
        case 'Enter':
            calculate();
            break;
    }
}

// Function to clear the Result Zone and return the result
function calculate() {
    const textZone = document.getElementsByClassName("res-container")[0];

    textZone.innerHTML = eval(textZone.innerHTML);
    textZone.innerHTML = textZone.innerHTML.toString().replace(/,/g, ".");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\+\-/g, "-");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\-\+/g, "-");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\-\-/g, "+");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\+\+/g, "+");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\/\//g, "/");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\/\*/g, "*");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\*\//g, "/");
    textZone.innerHTML = textZone.innerHTML.toString().replace(/\*\*/g, "*");
}

// Now let's add a sound every time a key is pressed
const keys = document.querySelectorAll('.key');

function pressedKey(e) {
    const audio = document.querySelector(`audio`);
    const key = document.querySelectorAll(`.key`);
    if (!audio) return;
    if (!key) return;

    audio.currentTime = 0;
    audio.play();
}

/*

keyCodes:

1 - 97
2 - 98
3 - 99
4 - 100
5 - 101
6 - 102
7 - 103
8 - 104
9 - 105
0 - 96

add - 107
sub - 109
multi - 106
div - 111

( - 57
) - 48
% = 53

*/