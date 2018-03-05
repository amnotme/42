-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Host: localhost:8889
-- Generation Time: Mar 05, 2018 at 07:08 AM
-- Server version: 5.6.38
-- PHP Version: 7.2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `rush01`
--

-- --------------------------------------------------------

--
-- Table structure for table `games`
--

CREATE TABLE `games` (
  `id` int(11) NOT NULL,
  `user` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `metadata` text NOT NULL,
  `max_number` int(11) NOT NULL,
  `game` varchar(255) NOT NULL,
  `status` enum('pending','started','','') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `games`
--

INSERT INTO `games` (`id`, `user`, `name`, `metadata`, `max_number`, `game`, `status`) VALUES
(1, 'asdasd', 'asdasd', 'as', 4, 'Tzo0OiJHYW1lIjo3OntzOjEyOiIAR2FtZQBfc3RhdGUiO2E6Njp7czo2OiJwbGF5ZXIiO2k6MDtzOjQ6InR1cm4iO2k6MDtzOjU6InBoYXNlIjtpOjA7czo0OiJzaGlwIjtOO3M6NjoiYWN0aXZlIjtiOjE7czo2OiJyZXN1bHQiO3M6MTU6IkdhbWUgaW4gc2Vzc2lvbiI7fXM6MTQ6IgBHYW1lAF9wbGF5ZXJzIjthOjE6e2k6MDtPOjQ6IlV', 'started'),
(2, 'sgtrgr', 'q43523r', '', 0, '', 'pending'),
(3, 'asdas', 'dsf', 'asdsa', 0, '', 'pending'),
(4, 'asdad', 'dsf', 'asdadasd', 0, '', 'pending'),
(5, 'asdad', 'dsf', 'asdadas', 0, '', 'pending'),
(6, 'asdad', 'dsf', 'asdad', 23, '', 'pending'),
(7, 'asdad', 'dsf', 'asdad', 23, '', 'pending'),
(8, 'asdad', 'dsf', 'asdad', 23, '', 'pending'),
(9, 'asdad', 'root', 'asdasd', 0, '', 'pending');

-- --------------------------------------------------------

--
-- Table structure for table `game_user`
--

CREATE TABLE `game_user` (
  `id` int(11) NOT NULL,
  `login` varchar(255) NOT NULL,
  `game_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_user`
--

INSERT INTO `game_user` (`id`, `login`, `game_id`) VALUES
(1, 'asda', 1),
(2, 'root', 0),
(6, 'root', 4),
(7, 'root', 3),
(8, 'root', 5),
(9, 'root', 2),
(11, 'sdf', 0),
(12, 'sdfss', 0),
(13, 'sdf', 1),
(14, 'sdfss', 1),
(37, 'rrr', 1);

-- --------------------------------------------------------

--
-- Table structure for table `user_info`
--

CREATE TABLE `user_info` (
  `id` int(11) NOT NULL,
  `login` varchar(255) NOT NULL,
  `passwd` varchar(255) NOT NULL,
  `wins` int(11) NOT NULL,
  `loses` int(11) NOT NULL,
  `email` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `user_info`
--

INSERT INTO `user_info` (`id`, `login`, `passwd`, `wins`, `loses`, `email`) VALUES
(1, 'rfsdf', 'wf2', 1, 2, 'adfdsf'),
(2, 'sfds', 'sdfsf', 34, 23, '23');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `games`
--
ALTER TABLE `games`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id` (`id`);

--
-- Indexes for table `game_user`
--
ALTER TABLE `game_user`
  ADD PRIMARY KEY (`login`,`game_id`),
  ADD KEY `id` (`id`);

--
-- Indexes for table `user_info`
--
ALTER TABLE `user_info`
  ADD PRIMARY KEY (`login`),
  ADD KEY `id` (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `games`
--
ALTER TABLE `games`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `game_user`
--
ALTER TABLE `game_user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;

--
-- AUTO_INCREMENT for table `user_info`
--
ALTER TABLE `user_info`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
