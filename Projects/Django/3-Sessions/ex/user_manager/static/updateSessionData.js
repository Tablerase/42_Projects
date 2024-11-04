// updateSessionData.js

function updateSessionUsername() {
  fetch('/user/get_session_username')
    .then(response => response.json())
    .then(data => {
      var element = document.getElementById('session_username');
      if (element) {
        element.innerHTML = 'Hello ' + data.username + '!';
      } else {
        console.error('Element with id session_username not found.');
      }
    })
    .catch(error => console.error('Error fetching session data:', error));
}

// Call the function every 42 seconds
setInterval(updateSessionUsername, 42000);

// Initial call to update immediately on page load
document.addEventListener('DOMContentLoaded', updateSessionUsername);