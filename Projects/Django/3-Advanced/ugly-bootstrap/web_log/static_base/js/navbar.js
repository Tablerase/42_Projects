// JavaScript to handle active link highlighting

function updateActiveLink() {
  const currentUrl = window.location.pathname;
  document.querySelectorAll('.nav-link').forEach(link => {
    if (link.getAttribute('href') === currentUrl) {
      link.classList.add('active');
    } else {
      link.classList.remove('active');
    }
  });
}

updateActiveLink();
