import React, { useState } from "react";
import axios from "axios";
import toast from "react-hot-toast";
import signupCSS from "./SignUp.module.css";
import Footer from "../components/Footer";

const SignUp = () => {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [phonenumber, setPhonenumber] = useState("");
  const [address, setAddress] = useState("");
  const [password, setPassword] = useState("");

  const handleSendMessage = async (e) => {
    e.preventDefault();
    await axios
      .post(
        "http://localhost:4000/api/v1/signup/signup",
        {
          password,
          name,
          email,
          phonenumber,
          address,
        },
        {
          withCredentials: true,
          headers: { "Content-Type": "application/json" },
        }
      )
      .then((res) => {
        toast.success(res.data.message);
        setName("");
        setEmail("");
        setPassword("");
        setPhonenumber("");
        setAddress("");
      })
      .catch((error) => {
        toast.error(error.response.data.message);
      });
  };

  return (
    <>
      
      <div className={signupCSS.Bdy}>
       
        <div className={signupCSS.signup_form}>
       
          <h2>Create Account</h2>
          <form onSubmit={handleSendMessage}>
            <label htmlFor="fullname">Full Name</label>
            <input
              type="text"
              id="fullname"
              name="fullname"
              placeholder="Full Name"
              value={name}
              onChange={(e) => setName(e.target.value)}
            />

            <label htmlFor="email">Email</label>
            <input
              type="email"
              id="email"
              name="email"
              placeholder="Email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
            />

            <label htmlFor="phone">Phone Number</label>
            <input
              type="tel"
              id="phone"
              name="phone"
              placeholder="Phone Number"
              value={phonenumber}
              onChange={(e) => setPhonenumber(e.target.value)}
            />

            <label htmlFor="address">Address</label>
            <input
              type="text"
              id="address"
              name="address"
              placeholder="Address"
              value={address}
              onChange={(e) => setAddress(e.target.value)}
            />

            <label htmlFor="password">Password</label>
            <input
              type="password"
              id="password"
              name="password"
              placeholder="Password"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
            />

            <button type="submit">SignUp</button>
          </form>
        </div>
      </div>
      <Footer />
    </>
  );
};

export default SignUp;
