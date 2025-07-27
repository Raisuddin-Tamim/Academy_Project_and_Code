import { Register } from "../models/registerSchema.js";

export const registerInfo = async (req, res) => {
  try {
    const { name, email, username, phonenumber,password } = req.body;
    if (!name || !email || !username || !phonenumber || !password) {
      return res.status(400).json({
        success: false,
        message: "All fields are required!",
      });
    }
    await Register.create({ name, email, username, phonenumber,password });
    res.status(200).json({
      success: true,
      message: "Registration Successfully!",
    });
  } catch (error) {
    if (error.name === "ValidationError") {
      let errorMessage = "";
      if (error.errors.name) {
        errorMessage += error.errors.name.message + " ";
      }
      if (error.errors.email) {
        errorMessage += error.errors.email.message + " ";
      }
      if (error.errors.username) {
        errorMessage += error.errors.username.message + " ";
      }
      if (error.errors.phonenumber) {
        errorMessage += error.errors.phonenumber.message + " ";
      }
      if (error.errors.password) {
        errorMessage += error.errors.password.message + " ";
      }
      return res.status(400).json({
        success: false,
        message: errorMessage,
      });
    }

    return res.status(500).json({
      success: false,
      message: "Unknown Error",
    });
  }
};