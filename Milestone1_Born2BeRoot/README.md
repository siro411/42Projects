*This project has been created as part of the 42 curriculum by anying.*

# Born2beRoot

## 📝 Description

**Born2beRoot** is a foundational system administration project at 42. The objective is to create a secure, minimal server environment using virtualization.

This project involves setting up a virtual machine (VM) with specific rules regarding partitioning, security policies, networking, and monitoring, simulating a real-world server setup without a graphical interface (GUI).

**Key Features:**
* **Virtualization:** Running a stable Linux server on a VM.
* **LVM & Encryption:** Using Logical Volume Management within encrypted partitions.
* **Security:** Strict SSH configuration, firewall (UFW), and strong password policies.
* **Sudo Policy:** Strict configuration for privilege escalation auditing.
* **Automated Monitoring:** A bash script broadcasting system metrics every 10 minutes.

---

## 🛠️ Instructions

### Prerequisites
* **Hypervisor:** VirtualBox (recommended) or UTM (for Apple Silicon).
* **ISO:** Debian 12 (Stable) or Rocky Linux 9 (Stable).

### Installation & Usage
1.  **Boot the VM:** Start the virtual machine in your hypervisor.
2.  **Login:**
    * **User:** `anying`
    * **Root:** `root`
    * **Password:** (As configured during setup, complying with the policy).
3.  **SSH Connection:**
    * The service runs on port **4242**
    * Connect via terminal: `ssh anying@localhost -p 4241`
4.  **Firewall:**
    * Check status: `sudo ufw status` (Should show port 4242 ALLOW).

### Monitoring Script
The monitoring script is located at `/usr/local/bin/monitoring.sh`.
* **Automatic Execution:** It runs every 10 minutes via `cron`.
* **Manual Execution:** `sudo /usr/local/bin/monitoring.sh`

---

## 📖 Project Description & Design Choices

### Operating System: Debian Stable
I chose **Debian** (Stable) for this project.
* **Pros:** High stability, extensive package repository (`apt`), and a large community documentation. It is ideal for learning system administration fundamentals.
* **Cons:** Software packages may not always be the absolute latest versions compared to rolling-release distros.

### Partitioning & LVM
* **Structure:** At least 2 encrypted partitions using LVM.
* **Reasoning:** Encryption ensures data security at rest. LVM allows for flexible volume management (resizing partitions) without reformating the disk.

### Security Implementation
* **SSH:** Root login is disabled. Port changed to `4242` to reduce automated bot scanning.
* **Password Policy:** Passwords expire every 30 days, require complex characters (Upper/Lower/Digit), and cannot match the username.
* **Sudo:** All sudo commands are logged to `/var/log/sudo/` for audit trails. TTY mode is enabled.

---

## ⚖️ Comparative Analysis

As part of the project defense, here is the comparison between key technologies:

### 1. Debian vs Rocky Linux
* **Debian:**
    * Based on `.deb` packages (dpkg/apt).
    * Community-driven, known for strict adherence to free software philosophies.
    * Uses **AppArmor** by default for mandatory access control.
* **Rocky Linux:**
    * Based on `.rpm` packages (rpm/dnf).
    * A downstream, binary-compatible rebuild of RHEL (Red Hat Enterprise Linux).
    * Uses **SELinux** by default, which offers fine-grained control but is more complex to configure.

### 2. AppArmor vs SELinux
* **AppArmor (Application Armor):**
    * **Path-based** MAC (Mandatory Access Control). Security profiles are bound to file paths.
    * Easier to learn and configure for beginners.
* **SELinux (Security-Enhanced Linux):**
    * **Label-based** MAC. Files, processes, and ports have security context labels (e.g., `httpd_sys_content_t`).
    * More granular and powerful, but significantly harder to troubleshoot.

### 3. UFW vs Firewalld
* **UFW (Uncomplicated Firewall):**
    * A frontend for `iptables` / `nftables`.
    * Designed for simplicity. Perfect for single-server setups where you just need to "allow port X".
* **Firewalld:**
    * Uses "Zones" (Public, Home, Work) to define trust levels for different network interfaces.
    * Better suited for laptops or servers that move between different networks.

### 4. VirtualBox vs UTM
* **VirtualBox:** Type-2 Hypervisor. Industry standard for x86 virtualization.
* **UTM:** A frontend for QEMU, primarily used on macOS (Apple Silicon) to emulate or virtualize operating systems that don't match the host architecture natively.

---

## 🌟 Bonus Part

The following bonus features have been implemented:

1.  **Functional WordPress Website:**
    * **Services:** `Lighttpd`, `MariaDB`, `PHP`.
    * **Why Lighttpd?** It uses less memory and CPU than Apache, making it suitable for a minimal VM environment.
    * **Access:** configured locally.
2.  **Additional Service: LiteSpeed**
    * **Purpose:**: It is a proprietary web server software. It is the fourth most popular web server, and is estimated to be used by 10% of websites.
3.  **Advanced Partitioning:**
    * The partition structure matches the bonus requirement (separate `/var`, `/home`, `/srv`, `/tmp`, etc.).

---

## 📚 Resources & AI Usage

### Resources
* [Debian Administrator's Handbook](https://debian-handbook.info/)
* [UFW Documentation](https://help.ubuntu.com/community/UFW)
* [Sudoers Manual](https://www.sudo.ws/man/1.8.15/sudoers.man.html)

### AI Usage
* **AI Tools Used:**  Gemini
* **Purpose:**
    * Used to verify correct syntax for `awk` and `grep` commands in `monitoring.sh`.
    * Used to clarify the differences between `apt` and `aptitude` for the defense preparation.
    * Used to troubleshoot `printf` formatting issues in the wall broadcast script.
* **Disclaimer:** All code and configurations were manually verified and tested to ensure they comply with the 42 subject rules (e.g., no usage of forbidden commands).
