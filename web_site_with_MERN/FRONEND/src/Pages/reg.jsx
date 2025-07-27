import React, { useState } from "react";
import axios from "axios";
import toast from "react-hot-toast";
import regCss from "./reg.module.css";
import  Footer from "../components/Footer";
import Navigation from "../components/Navigation/Navigation";

const registration = () => {
  const [name, setName] = useState("");
  const [username, setUName] = useState("");
  const [email, setEmail] = useState("");
  const [phonenumber, setPhonenumber] = useState("");
  const [password, setPassword] = useState("");

  const handleSendMessage = async (e) => {
    e.preventDefault();
    await axios
      .post(
        "http://localhost:4000/api/v1/register/register",
        {
          password,
          name,
          email,
          phonenumber,
          username,
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
        setUName("");
      })
      .catch((error) => {
        toast.error(error.response.data.message);
      });
  };

  return (
    <>
    <Navigation />
      <div className={regCss.bdy}>
        <form onSubmit={handleSendMessage}>
          <div className="title">
            <h2>REGISTER BOOK!<hr/></h2>
          </div>
          <div className="half">
            <div className="item">
              <label>Full-Name</label>
              <input
                type="text"
                name="name"
                value={name}
                onChange={(e) => setName(e.target.value)}
              />
            </div>
            <div className="item">
              <label>Username</label>
              <input
                type="text"
                name="username"
                value={username}
                onChange={(e) => setUName(e.target.value)}
              />
            </div>
          </div>
          <div className="half">
            <div className="item">
              <label>E-mail</label>
              <input
                type="text"
                name="email"
                value={email}
                onChange={(e) => setEmail(e.target.value)}
              />
            </div>
            <div className="item">
              <label>Password</label>
              <input
                type="password"
                name="password"
                value={password}
                onChange={(e) => setPassword(e.target.value)}
              />
            </div>
          </div>
          <div className="full">
            <div className="item">
              <label>Phone</label>
              <input
                type="text"
                name="phone"
                required
                value={phonenumber}
                onChange={(e) => setPhonenumber(e.target.value)}
              />
            </div>
          </div>
          <div className="action">
            <button type="submit" >REGISTER</button>
          </div>
        </form>
      </div>
      <Footer />
    </>
  );
};

export default registration;
