// JavaScript to handle redirection 

// Update radio checked according to current url
function updateCheckedTab() {
  const currentUrl = window.location.pathname;
  document.querySelectorAll('.tab').forEach(tab => {
    if (tab.getAttribute('data-url') === currentUrl) {
      tab.checked = true;
    }
  });
}
updateCheckedTab();

// Handler of link
document.querySelectorAll('.tab').forEach(tab => {
  tab.addEventListener('change', function() {
    if (this.checked) {
      window.location.href = this.getAttribute('data-url');
    }
  });
});
