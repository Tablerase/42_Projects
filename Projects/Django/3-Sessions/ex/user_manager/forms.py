from django import forms

class LoginForm(forms.Form):
  username = forms.CharField(max_length=100, required=True)
  password = forms.CharField(widget=forms.PasswordInput, required=True)

class RegisterForm(forms.Form):
  username = forms.CharField(max_length=100, required=True)
  password = forms.CharField(widget=forms.PasswordInput, required=True)
  confirm_password = forms.CharField(widget=forms.PasswordInput, required=True)