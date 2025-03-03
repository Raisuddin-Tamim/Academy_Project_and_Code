import { signup } from "../models/SignUpSchema.js";
import bcrypt from "bcryptjs";

export const signupInfo = async (req, res) => {
  try {
    const { name, email, phonenumber, address, password } = req.body;
    if (!name || !email || !password || !phonenumber || !address) {
      return res.status(400).json({
        success: false,
        message: "All fields are required!",
      });
    }

    const hashedPassword = await bcrypt.hash(password, 10);

    await signup.create({ name, email, phonenumber, address , password: hashedPassword});
    res.status(200).json({
      success: true,
      message: "Sign Up Successfully!",
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
      if (error.errors.phonenumber) {
        errorMessage += error.errors.phonenumber.message + " ";
      }
      if (error.errors.address) {
        errorMessage += error.errors.address.message + " ";
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
