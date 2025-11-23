"use strict";

var list = [];
const balance = 6000;
const priceMap = {
  "C": 500,
  "Zig": 1000,
  "Rust": 4000,
  "C++": 5001,
};

window.addEventListener("load", function(){
  loadCards();
  loadBalance();
});

function loadBalance() {
  const e = document.getElementById("balance");
  e.textContent = balance;
}

function loadCards() {
  const cards = document.getElementsByClassName('card');
  for (let i = 0; i < cards.length; i++) {
    const card = cards.item(i);
    const name = card.getElementsByClassName('product-name').item(0).textContent;
    const price = card.getElementsByClassName('product-price').item(0);
    price.textContent = `${priceMap[name]}🧠`;
    cards.item(i).addEventListener('click', () => saveItemToList(name, Math.floor(priceMap[name] * 0.9)));
  }
}

function onCartClick() {
  const dropdown = document.getElementById("cart-dropdown");
  dropdown.classList.toggle("show");
}

function clearCart() {
  list.length = 0;
  renderDropdown();
  alert("🗑️ Cleared the cart 🗑️");
}

function saveItemToList(name, price) {
  var total = price;
  list.forEach(item => {
    total += item[1];
  })
  if (total > balance) {
    alert("🤯 Not enough 🧠 to learn all of these 🤯");
    return;
  }
  list.push([name, price]);
  renderDropdown();
}

function deleteItem(index) {
  list.splice(index, 1);
  renderDropdown();
}

function renderDropdown() {
  const e = document.getElementById("total-cost");
  const dropdown = document.getElementById("cart-dropdown");
  let totalCost = 0;

  dropdown.innerHTML = '';
  for (let i = 0; i < list.length; i++) {
    const e = document.createElement('a');
    e.textContent = `❌ ${list[i][0]} (${list[i][1]})`;
    totalCost += list[i][1];
    e.addEventListener('click', () => deleteItem(i));
    dropdown.appendChild(e);
  }

  e.textContent = `(${totalCost}🧠)`;
}
